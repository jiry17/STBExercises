#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
struct point{
	int x[2],where;
}a[110000];
int d;
int operator < (point k1,point k2){
	return k1.x[d]<k2.x[d];
}
struct tree{
	point x;
	int L,R,U,D,father,l,r;
	long long ans,A,pre,w;
}t[110000];
struct ask{
	int pd,l,r;
	void scan(){
		scanf("%d%d%d",&pd,&l,&r);
	}
}q[110000];
int n,m,N,len,w[110000],where[110000],num1,num2;
long long A[110000];
void change(int k1){
	t[k1].U=max(max(t[t[k1].l].U,t[t[k1].r].U),t[k1].x.x[1]);
	t[k1].D=min(min(t[t[k1].l].D,t[t[k1].r].D),t[k1].x.x[1]);
	t[k1].L=min(min(t[t[k1].l].L,t[t[k1].r].L),t[k1].x.x[0]);
	t[k1].R=max(max(t[t[k1].l].R,t[t[k1].r].R),t[k1].x.x[0]);
}
void buildtree(int k1,int k2,int k3,int k4){
	d=k4; int mid=k2+k3>>1; nth_element(a+k2,a+mid,a+k3+1);
	t[k1].x=a[mid]; t[k1].ans=A[t[k1].x.x[1]]-A[t[k1].x.x[0]-1];
	t[k1].w=t[k1].ans; where[t[k1].x.where]=k1;
	if (mid>k2){
		len++; t[len].father=k1; t[k1].l=len; buildtree(len,k2,mid-1,k4^1);
	}
	if (mid<k3){
		len++; t[len].father=k1; t[k1].r=len; buildtree(len,mid+1,k3,k4^1);
	}
	change(k1);
}
void add(int k1,long long k2,long long k3){
	if (k1==0) return;
	t[k1].ans=min(t[k1].w+k3,t[k1].ans);
	t[k1].w+=k2;
	t[k1].pre=min(t[k1].A+k3,t[k1].pre);
	t[k1].A+=k2;
}
void pushdown(int k1){
	add(t[k1].l,t[k1].A,t[k1].pre);
	add(t[k1].r,t[k1].A,t[k1].pre);
	t[k1].A=0; t[k1].pre=0;
}
void change(int k1,int k2,int k3){
	num1++;
	if (k1==0||t[k1].U<k2||t[k1].L>k2) return;
	if (t[k1].D>=k2&&t[k1].R<=k2){
		add(k1,k3,min(k3,0)); return;
	}
	pushdown(k1);
	if (t[k1].x.x[0]<=k2&&t[k1].x.x[1]>=k2){
		t[k1].w+=k3; t[k1].ans=min(t[k1].ans,t[k1].w);
	}
	change(t[k1].l,k2,k3); change(t[k1].r,k2,k3);
}
void findans(int k1){
	num2++;
	if (k1==0) return;
	findans(t[k1].father); pushdown(k1);
}
int main(){
	//freopen("2.in","r",stdin);
	scanf("%d%d",&n,&m);
	t[0].U=0; t[0].D=1e9; t[0].L=1e9; t[0].R=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&w[i]); A[i]=A[i-1]+w[i];
	}
	for (int i=1;i<=m;i++){
		q[i].scan();
		if (q[i].pd==2){
			a[++N].x[0]=q[i].l; a[N].x[1]=q[i].r; a[N].where=i;
		}
	}
	len=1; buildtree(1,1,N,0);
//	for (int i=1;i<=len;i++) cout<<t[i].father<<" "<<t[i].l<<" "<<t[i].r<<" "<<t[i].x.x[0]<<" "<<t[i].x.x[1]<<" "<<t[i].ans<<endl;
//	while (1);
	for (int i=1;i<=m;i++){
	//	if (i%1000==0) cout<<i<<" "<<num1<<" "<<num2<<endl;
		if (q[i].pd==1){
			change(1,q[i].l,q[i].r-w[q[i].l]); w[q[i].l]=q[i].r;
	//	cout<<"fa "<<q[i].l<<" "<<q[i].r<<endl;
	//	for (int j=1;j<=len;j++) cout<<t[j].w<<" "<<t[j].ans<<" "<<t[j].pre<<" "<<t[j].A<<endl;
	//	cout<<endl<<endl;
		} else{
			findans(where[i]); printf("%lld\n",t[where[i]].ans);
		}
	}
	return 0;
}
