#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=500100,inf=2e9;
int A[N<<2],B[N<<2],preA[N<<2],preB[N<<2],n,m,mi[N<<2],num[N<<2],se[N<<2],flag;
void addall(int k1,int k2){
	num[k1]=min(num[k1],k2+mi[k1]);
	A[k1]+=k2; B[k1]+=k2; mi[k1]+=k2; se[k1]+=k2;
	preA[k1]=min(preA[k1],A[k1]);
	preB[k1]=min(preB[k1],B[k1]);
}
void addall(int k1,int a,int prea,int b,int preb){
	num[k1]=min(num[k1],mi[k1]+prea);
	preA[k1]=min(preA[k1],prea+A[k1]);
	preB[k1]=min(preB[k1],preb+B[k1]);
	A[k1]+=a; B[k1]+=b; mi[k1]+=a; se[k1]+=b;
	se[k1]=min(se[k1],inf);
}
void pushdown(int k1){
	int now=min(mi[k1*2],mi[k1*2+1]);
	if (mi[k1*2]==now) addall(k1*2,A[k1],preA[k1],B[k1],preB[k1]);
	else addall(k1*2,B[k1],preB[k1],B[k1],preB[k1]);
	if (mi[k1*2+1]==now) addall(k1*2+1,A[k1],preA[k1],B[k1],preB[k1]);
	else addall(k1*2+1,B[k1],preB[k1],B[k1],preB[k1]);
	A[k1]=0; preA[k1]=0; B[k1]=0; preB[k1]=0;
}
void change(int k1){
	int l=k1*2,r=k1*2+1;
	if (mi[l]==mi[r]){
		mi[k1]=mi[l]; se[k1]=min(se[l],se[r]);
	} else if (mi[l]<mi[r]){
		mi[k1]=mi[l]; se[k1]=min(se[l],mi[r]);
	} else {
		mi[k1]=mi[r]; se[k1]=min(se[r],mi[l]);
	}
	num[k1]=min(num[l],num[r]);
}
void add(int k1,int k2,int k3,int k4,int k5,int k6){
	if (k2>k5||k3<k4) return;
	if (k2>=k4&&k3<=k5){
		addall(k1,k6); return;
	}
	int mid=k2+k3>>1; pushdown(k1);
	add(k1*2,k2,mid,k4,k5,k6);
	add(k1*2+1,mid+1,k3,k4,k5,k6);
	change(k1);
}
void addinA(int k1,int k2){
	k2-=mi[k1];
	num[k1]=min(num[k1],mi[k1]+k2);
	preA[k1]=min(preA[k1],A[k1]+k2);
	A[k1]+=k2; mi[k1]+=k2;
}
void down(int k1,int k2,int k3,int k4){
	if (mi[k1]>=k4) return;
	if (se[k1]>k4){
		addinA(k1,k4); return;
	}
	pushdown(k1); int mid=k2+k3>>1;
	down(k1*2,k2,mid,k4);
	down(k1*2+1,mid+1,k3,k4);
	change(k1);
}
void changeall(int k1,int k2,int k3,int k4,int k5,int k6){
	if (k2>k5||k3<k4) return;
	if (k2>=k4&&k3<=k5){
		down(k1,k2,k3,k6); return;
	}
	pushdown(k1); int mid=k2+k3>>1;
	changeall(k1*2,k2,mid,k4,k5,k6);
	changeall(k1*2+1,mid+1,k3,k4,k5,k6);
	change(k1);
}
void buildtree(int k1,int k2,int k3){
	if (k2==k3){
		scanf("%d",&mi[k1]); se[k1]=inf; num[k1]=mi[k1]; return;
	}
	int mid=k2+k3>>1;
	buildtree(k1*2,k2,mid);
	buildtree(k1*2+1,mid+1,k3);
	change(k1);
}
int findpre(int k1,int k2,int k3,int k4,int k5){
	if (k2>k5||k3<k4) return inf;
	if (k2>=k4&&k3<=k5) return num[k1];
	int mid=k2+k3>>1; pushdown(k1);
	return min(findpre(k1*2,k2,mid,k4,k5),findpre(k1*2+1,mid+1,k3,k4,k5));
}
int findmi(int k1,int k2,int k3,int k4,int k5){
	if (k2>k5||k3<k4) return inf;
	if (k2>=k4&&k3<=k5) return mi[k1];
	int mid=k2+k3>>1; pushdown(k1);
	return min(findmi(k1*2,k2,mid,k4,k5),findmi(k1*2+1,mid+1,k3,k4,k5));
}
int main(){
	scanf("%d%d",&n,&m);
	buildtree(1,1,n);
	for (;m;m--){
		int k1,k2,k3; scanf("%d%d%d",&k1,&k2,&k3);
	//	cout<<"cha "<<k1<<" "<<k2<<" "<<k3<<endl;
		if (k1==4){
			int kk=findpre(1,1,n,k2,k3);
			printf("%d\n",kk);
		} else if (k1==3) printf("%d\n",findmi(1,1,n,k2,k3));
		else{
			int k4; scanf("%d",&k4);
			if (k1==1) add(1,1,n,k2,k3,k4);
			else changeall(1,1,n,k2,k3,k4);
		}
	}
	return 0;
}
