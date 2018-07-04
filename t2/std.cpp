#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N=210000,inf=2e9;
int mi[N<<2],ma[N<<2],tmi[N<<2],tma[N<<2],semi[N<<2],sema[N<<2],n,m,A[N<<2],B[N<<2],C[N<<2],size[N<<2];
int tA[N<<2],tB[N<<2],tC[N<<2],pd[N<<2];
long long num[N<<2];
void change(int k1){
	int l=k1*2,r=k1*2+1;
	if (mi[l]==mi[r]){
		mi[k1]=mi[l]; semi[k1]=min(semi[l],semi[r]); tmi[k1]=tmi[l]+tmi[r];
	} else if (mi[l]<mi[r]){
		mi[k1]=mi[l]; semi[k1]=min(semi[l],mi[r]); tmi[k1]=tmi[l];
	} else {
		mi[k1]=mi[r]; semi[k1]=min(mi[l],semi[r]); tmi[k1]=tmi[r];
	}
	if (ma[l]==ma[r]){
		ma[k1]=ma[l]; sema[k1]=max(sema[l],sema[r]); tma[k1]=tma[l]+tma[r];
	} else if (ma[l]>ma[r]){
		ma[k1]=ma[l]; sema[k1]=max(sema[l],ma[r]); tma[k1]=tma[l];
	} else {
		ma[k1]=ma[r]; sema[k1]=max(ma[l],sema[r]); tma[k1]=tma[r];
	}
	num[k1]=num[l]+num[r];
	if (mi[k1]!=ma[k1]) pd[k1]=0; else pd[k1]=1;
}
void addA(int k1,int k2,int k3){
	mi[k1]+=k2; num[k1]+=1ll*tmi[k1]*k3; A[k1]+=k2; tA[k1]+=k3;
	if (tmi[k1]+tma[k1]==size[k1]) sema[k1]+=k2;
}
void addB(int k1,int k2,int k3){
	if (pd[k1]==0) num[k1]+=1ll*(size[k1]-tmi[k1]-tma[k1])*k3; B[k1]+=k2; tB[k1]+=k3;
	if (tmi[k1]+tma[k1]<size[k1]){
		semi[k1]+=k2; sema[k1]+=k2;
	}
}
void addC(int k1,int k2,int k3){
	ma[k1]+=k2; if (pd[k1]==0) num[k1]+=1ll*tma[k1]*k3; C[k1]+=k2; tC[k1]+=k3;
	if (tmi[k1]+tma[k1]==size[k1]) semi[k1]+=k2;
}
void pushdown(int k1){
	int l=k1*2,L=min(mi[l],mi[l+1]),R=max(ma[l],ma[l+1]);
	if (mi[l]==L) addA(l,A[k1],tA[k1]); else if (mi[l]==R) addA(l,C[k1],tC[k1]); else addA(l,B[k1],tB[k1]);
	if (ma[l]==L) addC(l,A[k1],tA[k1]); else if (ma[l]==R) addC(l,C[k1],tC[k1]); else addC(l,B[k1],tB[k1]);
	addB(l,B[k1],tB[k1]);
	l++;
	if (mi[l]==L) addA(l,A[k1],tA[k1]); else if (mi[l]==R) addA(l,C[k1],tC[k1]); else addA(l,B[k1],tB[k1]);
	if (ma[l]==L) addC(l,A[k1],tA[k1]); else if (ma[l]==R) addC(l,C[k1],tC[k1]); else addC(l,B[k1],tB[k1]);
	addB(l,B[k1],tB[k1]);
	A[k1]=0; tA[k1]=0; B[k1]=0; tB[k1]=0; C[k1]=0; tC[k1]=0;
}
void buildtree(int k1,int k2,int k3){
	size[k1]=k3-k2+1;
	if (k2==k3){
		int k4; scanf("%d",&k4); mi[k1]=k4; ma[k1]=k4; semi[k1]=inf; sema[k1]=-inf; tmi[k1]=1; tma[k1]=1;
		pd[k1]=1;
		return;
	}
	int mid=k2+k3>>1;
	buildtree(k1*2,k2,mid); buildtree(k1*2+1,mid+1,k3);
	change(k1);
}
long long findans(int k1,int k2,int k3,int k4,int k5){
	if (k2>k5||k3<k4) return 0;
	if (k2>=k4&&k3<=k5) return num[k1];
	int mid=k2+k3>>1; pushdown(k1);
	return findans(k1*2,k2,mid,k4,k5)+findans(k1*2+1,mid+1,k3,k4,k5);
}
void down1(int k1,int k2,int k3,int k4){
	if (mi[k1]>=k4) return;
	if (semi[k1]>k4){
		int now=k4-mi[k1]; addA(k1,now,1);
		if (pd[k1]==1) addB(k1,now,1),addC(k1,now,1);
		return;
	}
	int mid=k2+k3>>1; pushdown(k1);
	down1(k1*2,k2,mid,k4);
	down1(k1*2+1,mid+1,k3,k4);
	change(k1);
}
void down2(int k1,int k2,int k3,int k4){
	//cout<<"fa "<<k1<<" "<<k2<<" "<<k3<<" "<<k4<<" "<<ma[k1]<<" "<<sema[k1]<<endl;
	if (ma[k1]<=k4) return;
	if (sema[k1]<k4){
		int now=k4-ma[k1]; addC(k1,now,1);
		if (pd[k1]==1) addB(k1,now,1),addA(k1,now,1);
		return;
	}
	int mid=k2+k3>>1; pushdown(k1);
	down2(k1*2,k2,mid,k4);
	down2(k1*2+1,mid+1,k3,k4);
	change(k1);
}
void getmax(int k1,int k2,int k3,int k4,int k5,int k6){
	if (k2>k5||k3<k4) return;
	if (k2>=k4&&k3<=k5){
		down1(k1,k2,k3,k6); return;
	}
	int mid=k2+k3>>1; pushdown(k1);
	getmax(k1*2,k2,mid,k4,k5,k6);
	getmax(k1*2+1,mid+1,k3,k4,k5,k6);
	change(k1);
}
void getmin(int k1,int k2,int k3,int k4,int k5,int k6){
	if (k2>k5||k3<k4) return;
	if (k2>=k4&&k3<=k5){
		down2(k1,k2,k3,k6); return;
	}
//	cout<<"fa "<<k1<<" "<<k2<<" "<<k3<<" "<<k4<<" "<<k5<<" "<<k6<<" "<<ma[k1]<<" "<<sema[k1]<<endl;
	int mid=k2+k3>>1; pushdown(k1);
	getmin(k1*2,k2,mid,k4,k5,k6);
	getmin(k1*2+1,mid+1,k3,k4,k5,k6);
	change(k1);
}
void addall(int k1,int k2,int k3,int k4,int k5,int k6){
	if (k2>k5||k3<k4) return;
	if (k2>=k4&&k3<=k5){
		addA(k1,k6,1); addB(k1,k6,1); addC(k1,k6,1); return;
	}
	int mid=k2+k3>>1; pushdown(k1);
	addall(k1*2,k2,mid,k4,k5,k6);
	addall(k1*2+1,mid+1,k3,k4,k5,k6);
	change(k1);
}
int main(){
	scanf("%d%d",&n,&m);
	buildtree(1,1,n);
	for (;m;m--){
		int k1,k2,k3; scanf("%d%d%d",&k1,&k2,&k3);
		if (k1==1){
			int k4; scanf("%d",&k4); getmax(1,1,n,k2,k3,k4);
		} else if (k1==2){
			int k4; scanf("%d",&k4); getmin(1,1,n,k2,k3,k4);
		} else if (k1==3){
			int k4; scanf("%d",&k4); if (k4!=0) addall(1,1,n,k2,k3,k4);
		} else if (k1==4) printf("%lld\n",findans(1,1,n,k2,k3));
	}
	return 0;
}
