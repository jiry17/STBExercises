#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
namespace fastIO{
    #define BUF_SIZE 100000
    #define OUT_SIZE 100000
    #define ll long long
    //fread->read
    bool IOerror=0;
    inline char nc(){
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if (p1==pend){
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if (pend==p1){IOerror=1;return -1;}
            //{printf("IO error!\n");system("pause");for (;;);exit(0);}
        }
        return *p1++;
    }
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
    inline void read(int &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(ll &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(double &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (ch=='.'){
            double tmp=1; ch=nc();
            for (;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0');
        }
        if (sign)x=-x;
    }
    inline void read(char *s){
        char ch=nc();
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        for (;!blank(ch)&&!IOerror;ch=nc())*s++=ch;
        *s=0;
    }
    inline void read(char &c){
        for (c=nc();blank(c);c=nc());
        if (IOerror){c=-1;return;}
    }
    //getchar->read
    inline void read1(int &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (bo)x=-x;
    }
    inline void read1(ll &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (bo)x=-x;
    }
    inline void read1(double &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (ch=='.'){
            double tmp=1;
            for (ch=getchar();ch>='0'&&ch<='9';tmp/=10.0,x+=tmp*(ch-'0'),ch=getchar());
        }
        if (bo)x=-x;
    }
    inline void read1(char *s){
        char ch=getchar();
        for (;blank(ch);ch=getchar());
        for (;!blank(ch);ch=getchar())*s++=ch;
        *s=0;
    }
    inline void read1(char &c){for (c=getchar();blank(c);c=getchar());}
    //scanf->read
    inline void read2(int &x){scanf("%d",&x);}
    inline void read2(ll &x){
        #ifdef _WIN32
            scanf("%I64d",&x);
        #else
        #ifdef __linux
            scanf("%lld",&x);
        #else
            puts("error:can't recognize the system!");
        #endif
        #endif
    }
    inline void read2(double &x){scanf("%lf",&x);}
    inline void read2(char *s){scanf("%s",s);}
    inline void read2(char &c){scanf(" %c",&c);}
    inline void readln2(char *s){gets(s);}
    //fwrite->write
    struct Ostream_fwrite{
        char *buf,*p1,*pend;
        Ostream_fwrite(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;}
        void out(char ch){
            if (p1==pend){
                fwrite(buf,1,BUF_SIZE,stdout);p1=buf;
            }
            *p1++=ch;
        }
        void print(int x){
            static char s[15],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1);
        }
        void println(int x){
            static char s[15],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1); out('\n');
        }
        void print(ll x){
            static char s[25],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1);
        }
        void println(ll x){
            static char s[25],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1); out('\n');
        }
        void print(double x,int y){
            static ll mul[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,
                1000000000,10000000000LL,100000000000LL,1000000000000LL,10000000000000LL,
                100000000000000LL,1000000000000000LL,10000000000000000LL,100000000000000000LL};
            if (x<-1e-12)out('-'),x=-x;x*=mul[y];
            ll x1=(ll)floor(x); if (x-floor(x)>=0.5)++x1;
            ll x2=x1/mul[y],x3=x1-x2*mul[y]; print(x2);
            if (y>0){out('.'); for (size_t i=1;i<y&&x3*mul[i]<mul[y];out('0'),++i); print(x3);}
        }
        void println(double x,int y){print(x,y);out('\n');}
        void print(char *s){while (*s)out(*s++);}
        void println(char *s){while (*s)out(*s++);out('\n');}
        void flush(){if (p1!=buf){fwrite(buf,1,p1-buf,stdout);p1=buf;}}
        ~Ostream_fwrite(){flush();}
    }Ostream;
    inline void print(int x){Ostream.print(x);}
    inline void println(int x){Ostream.println(x);}
    inline void print(char x){Ostream.out(x);}
    inline void println(char x){Ostream.out(x);Ostream.out('\n');}
    inline void print(ll x){Ostream.print(x);}
    inline void println(ll x){Ostream.println(x);}
    inline void print(double x,int y){Ostream.print(x,y);}
    inline void println(double x,int y){Ostream.println(x,y);}
    inline void print(char *s){Ostream.print(s);}
    inline void println(char *s){Ostream.println(s);}
    inline void println(){Ostream.out('\n');}
    inline void flush(){Ostream.flush();}
    //puts->write
    char Out[OUT_SIZE],*o=Out;
    inline void print1(int x){
        static char buf[15];
        char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x;
        while(x)*p1++=x%10+'0',x/=10;
        while(p1--!=buf)*o++=*p1;
    }
    inline void println1(int x){print1(x);*o++='\n';}
    inline void print1(ll x){
        static char buf[25];
        char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x;
        while(x)*p1++=x%10+'0',x/=10;
        while(p1--!=buf)*o++=*p1;
    }
    inline void println1(ll x){print1(x);*o++='\n';}
    inline void print1(char c){*o++=c;}
    inline void println1(char c){*o++=c;*o++='\n';}
    inline void print1(char *s){while (*s)*o++=*s++;}
    inline void println1(char *s){print1(s);*o++='\n';}
    inline void println1(){*o++='\n';}
    inline void flush1(){if (o!=Out){if (*(o-1)=='\n')*--o=0;puts(Out);}}
    struct puts_write{
        ~puts_write(){flush1();}
    }_puts;
    inline void print2(int x){printf("%d",x);}
    inline void println2(int x){printf("%d\n",x);}
    inline void print2(char x){printf("%c",x);}
    inline void println2(char x){printf("%c\n",x);}
    inline void print2(ll x){
        #ifdef _WIN32
            printf("%I64d",x);
        #else
        #ifdef __linux
            printf("%lld",x);
        #else
            puts("error:can't recognize the system!");
        #endif
        #endif
    }
    inline void println2(ll x){print2(x);printf("\n");}
    inline void println2(){printf("\n");}
    #undef ll
    #undef OUT_SIZE
    #undef BUF_SIZE
};
using namespace fastIO;
const int N=500010,inf=2e9;
int mi[N<<2],ma[N<<2],semi[N<<2],sema[N<<2],n,m,premi[N<<2],prema[N<<2];
int A[N<<2],Ami[N<<2],Ama[N<<2],B[N<<2],Bmi[N<<2],Bma[N<<2],C[N<<2],Cmi[N<<2],Cma[N<<2],preA,preC,prei,prea;
void change(int k1){
	int l=k1*2,r=k1*2+1;
	mi[k1]=min(mi[l],mi[r]); ma[k1]=max(ma[l],ma[r]);
	premi[k1]=min(premi[l],premi[r]); prema[k1]=max(prema[l],prema[r]);
	if (mi[l]==mi[r]) semi[k1]=min(semi[l],semi[r]);
	else if (mi[l]<mi[r]) semi[k1]=min(semi[l],mi[r]);
	else semi[k1]=min(mi[l],semi[r]);
	if (ma[l]==ma[r]) sema[k1]=max(sema[l],sema[r]);
	else if (ma[l]<ma[r]) sema[k1]=max(ma[l],sema[r]);
	else sema[k1]=max(sema[l],ma[r]);
}
void buildtree(int k1,int k2,int k3){
	if (k2==k3){
		read(mi[k1]); ma[k1]=mi[k1]; semi[k1]=inf; sema[k1]=-inf;
		premi[k1]=mi[k1]; prema[k1]=ma[k1]; return;
	}
	int mid=k2+k3>>1;
	buildtree(k1*2,k2,mid); buildtree(k1*2+1,mid+1,k3);
	change(k1);
}
void addall(int k1,int k2){
	if (abs(semi[k1])!=inf) semi[k1]+=k2;
	if (abs(sema[k1])!=inf) sema[k1]+=k2;
	mi[k1]+=k2; ma[k1]+=k2;
	premi[k1]=min(premi[k1],mi[k1]);
	prema[k1]=max(prema[k1],ma[k1]);
	A[k1]+=k2; Ami[k1]=min(Ami[k1],A[k1]); Ama[k1]=max(Ama[k1],A[k1]);
	B[k1]+=k2; Bmi[k1]=min(Bmi[k1],B[k1]); Bma[k1]=max(Bma[k1],B[k1]);
	C[k1]+=k2; Cmi[k1]=min(Cmi[k1],C[k1]); Cma[k1]=max(Cma[k1],C[k1]);
}
void addA(int k1,int k2,int k3,int k4){
	premi[k1]=min(premi[k1],mi[k1]+k3); 
	if (prea==preA) sema[k1]+=k2;
	mi[k1]+=k2;
	Ami[k1]=min(Ami[k1],A[k1]+k3);
	Ama[k1]=max(Ama[k1],A[k1]+k4);
	A[k1]+=k2;
}
void addB(int k1,int k2,int k3,int k4){
	if (prei!=preC&&abs(semi[k1])!=inf) semi[k1]+=k2;
	if (prea!=preA&&abs(sema[k1])!=inf) sema[k1]+=k2;
	Bmi[k1]=min(Bmi[k1],B[k1]+k3);
	Bma[k1]=max(Bma[k1],B[k1]+k4);
	B[k1]+=k2;
}
void addC(int k1,int k2,int k3,int k4){
	prema[k1]=max(prema[k1],ma[k1]+k4);
	if (prei==preC) semi[k1]+=k2;
	ma[k1]+=k2;
	Cmi[k1]=min(Cmi[k1],C[k1]+k3);
	Cma[k1]=max(Cma[k1],C[k1]+k4);
	C[k1]+=k2;
}
void pushdown(int k1){
	int l=k1*2,r=k1*2+1; int minum=min(mi[l],mi[r]),manum=max(ma[l],ma[r]);
	preA=mi[l],preC=ma[l],prei=semi[l],prea=sema[l];
	if (mi[l]==minum) addA(l,A[k1],Ami[k1],Ama[k1]);
	else if (mi[l]==manum) addA(l,C[k1],Cmi[k1],Cma[k1]);
	else addA(l,B[k1],Bmi[k1],Bma[k1]);
	addB(l,B[k1],Bmi[k1],Bma[k1]);
	if (ma[l]==manum) addC(l,C[k1],Cmi[k1],Cma[k1]);
	else if (ma[l]==minum) addC(l,A[k1],Ami[k1],Ama[k1]);
	else addC(l,B[k1],Bmi[k1],Bma[k1]);
	preA=mi[r],preC=ma[r],prei=semi[r],prea=sema[r];
	if (mi[r]==minum) addA(r,A[k1],Ami[k1],Ama[k1]);
	else if (mi[r]==manum) addA(r,C[k1],Cmi[k1],Cma[k1]);
	else addA(r,B[k1],Bmi[k1],Bma[k1]);
	addB(r,B[k1],Bmi[k1],Bma[k1]);
	if (ma[r]==manum) addC(r,C[k1],Cmi[k1],Cma[k1]);
	else if (ma[r]==minum) addC(r,A[k1],Ami[k1],Ama[k1]);
	else addC(r,B[k1],Bmi[k1],Bma[k1]);
	A[k1]=0; Ami[k1]=0; Ama[k1]=0;
	B[k1]=0; Bmi[k1]=0; Bma[k1]=0;
	C[k1]=0; Cmi[k1]=0; Cma[k1]=0;
}
void add(int k1,int k2,int k3,int k4,int k5,int k6){
	if (k2>k5||k3<k4) return;
	if (k2>=k4&&k3<=k5){
		addall(k1,k6);
		return;
	}
	int mid=k2+k3>>1; pushdown(k1);
	add(k1*2,k2,mid,k4,k5,k6); add(k1*2+1,mid+1,k3,k4,k5,k6);
	change(k1);
}
void downma(int k1,int k2,int k3,int k4){
	//cout<<"downma "<<k1<<" "<<k2<<" "<<k3<<" "<<k4<<" "<<mi[k1]<<" "<<semi[k1]<<endl;
	if (mi[k1]>=k4) return;
	if (semi[k1]>k4){
		int num=k4-mi[k1]; preA=mi[k1]; preC=ma[k1]; prei=semi[k1]; prea=sema[k1];
	//	cout<<"change "<<k1<<" "<<k2<<" "<<k3<<" "<<k4<<" "<<num<<endl;
		if (ma[k1]==mi[k1]) addC(k1,num,0,num);
		addA(k1,num,0,num);
		//cout<<mi[k1]<<endl;
		return;
	}
	int mid=k2+k3>>1; pushdown(k1);
	downma(k1*2,k2,mid,k4);
	downma(k1*2+1,mid+1,k3,k4);
	change(k1);
}
void downmi(int k1,int k2,int k3,int k4){
	if (ma[k1]<=k4) return;
	if (sema[k1]<k4){
		int num=k4-ma[k1]; preA=mi[k1]; preC=ma[k1]; prei=semi[k1]; prea=sema[k1];
		if (mi[k1]==ma[k1]) addA(k1,num,num,0);
		addC(k1,num,num,0);
		return;
	}
	int mid=k2+k3>>1; pushdown(k1);
	downmi(k1*2,k2,mid,k4);
	downmi(k1*2+1,mid+1,k3,k4);
	change(k1);
}
void getma(int k1,int k2,int k3,int k4,int k5,int k6){
	if (k2>k5||k3<k4) return;
	if (k2>=k4&&k3<=k5){
		downma(k1,k2,k3,k6); return;
	}
	int mid=k2+k3>>1; pushdown(k1);
	getma(k1*2,k2,mid,k4,k5,k6); getma(k1*2+1,mid+1,k3,k4,k5,k6);
	change(k1);
}
void getmi(int k1,int k2,int k3,int k4,int k5,int k6){
	if (k2>k5||k3<k4) return;
	if (k2>=k4&&k3<=k5){
		downmi(k1,k2,k3,k6); return;
	}
	int mid=k2+k3>>1; pushdown(k1);
	getmi(k1*2,k2,mid,k4,k5,k6); getmi(k1*2+1,mid+1,k3,k4,k5,k6);
	change(k1);
}
int findmi(int k1,int k2,int k3,int k4,int k5){
	if (k2>k5||k3<k4) return inf;
//	cout<<"findmi "<<k1<<" "<<k2<<" "<<k3<<" "<<k4<<" "<<mi[k1]<<" "<<semi[k1]<<endl;
	if (k2>=k4&&k3<=k5) return premi[k1];
	int mid=k2+k3>>1; pushdown(k1);
	return min(findmi(k1*2,k2,mid,k4,k5),findmi(k1*2+1,mid+1,k3,k4,k5));
}
int findmin(int k1,int k2,int k3,int k4,int k5){
	if (k2>k5||k3<k4) return inf;
	if (k2>=k4&&k3<=k5) return mi[k1];
	int mid=k2+k3>>1; pushdown(k1);
	return min(findmin(k1*2,k2,mid,k4,k5),findmin(k1*2+1,mid+1,k3,k4,k5));
}
int findma(int k1,int k2,int k3,int k4,int k5){
	if (k2>k5||k3<k4) return -inf;
	if (k2>=k4&&k3<=k5){
		//cout<<"fa "<<k1<<" "<<k2<<" "<<k3<<" "<<prema[k1]<<endl;
		return prema[k1];
	}
	int mid=k2+k3>>1; pushdown(k1);
	return max(findma(k1*2,k2,mid,k4,k5),findma(k1*2+1,mid+1,k3,k4,k5));
}
void print(int k1,int k2,int k3){
	if (k2==k3){
		cout<<mi[k1]<<" "; return;
	}
	int mid=k2+k3>>1; pushdown(k1);
	print(k1*2,k2,mid); print(k1*2+1,mid+1,k3);
}
void check(int k1,int k2,int k3){
	cout<<"fa "<<k1<<" "<<k2<<" "<<k3<<" "<<mi[k1]<<" "<<ma[k1]<<" "<<semi[k1]<<" "<<sema[k1]<<endl;
	if (k2==k3){
		return;
	}
	int mid=k2+k3>>1; pushdown(k1);
	check(k1*2,k2,mid); check(k1*2+1,mid+1,k3);
	int k4=semi[k1],k5=sema[k1],k6=mi[k1],k7=ma[k1];
	change(k1);
}
int main(){
//	freopen("data.in","r",stdin);
//	freopen("sequence7.in","r",stdin);
//	freopen("sequence7.out","w",stdout);
	read(n); read(m);
	buildtree(1,1,n); int num=0;
	for (;m;m--){
		int k1,l,r; read(k1); read(l); read(r);
		//if (k1==3) k1=6;
		if (k1==1){
			int c; read(c); add(1,1,n,l,r,c);
		} else if (k1==2){
			int d; read(d); getma(1,1,n,l,r,d);
		} else if (k1==5){
			int e; read(e); getmi(1,1,n,l,r,e);
		} else if (k1==4) println(findmi(1,1,n,l,r));
		else if (k1==6) println(findma(1,1,n,l,r));
		else println(findmin(1,1,n,l,r));
	//	check(1,1,n);
	}
	return 0;
}
