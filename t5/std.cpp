#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert> 
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
const int N=100010,inf=2e9;
int A[N<<2],B[N<<2],C[N<<2],D[N<<2],E[N<<2],F[N<<2];
int mi[N<<2],se[N<<2],mima[N<<2],mise[N<<2],sema[N<<2],sese[N<<2],size[N<<2];
int t[N<<2],tmi[N<<2],tse[N<<2];
long long sum[N<<2],tot[N<<2];
int n,m;
void update(int &k1,int &k2,int &k3,int k4,int k5,int k6){
    if (k1==k4){
        k2=max(k2,k5); k3+=k6;
    } else if (k1<k4){
        k2=max(k1,k5); k1=k4; k3=k6;
    } else k2=max(k2,k4); 
}
void change(int k1){
    int l=k1*2,r=k1*2+1;
    sum[k1]=sum[l]+sum[r];
    tot[k1]=tot[l]+tot[r];
    mima[k1]=-inf; mise[k1]=-inf; 
    sema[k1]=-inf; sese[k1]=-inf;
    if (mi[l]==mi[r]){
        mi[k1]=mi[l]; t[k1]=t[l]+t[r];
        se[k1]=min(se[l],se[r]);
        update(mima[k1],mise[k1],tmi[k1],mima[l],mise[l],tmi[l]);
        update(mima[k1],mise[k1],tmi[k1],mima[r],mise[r],tmi[r]);
//      cout<<t[k1]<<endl;
    } else if (mi[l]<mi[r]){
        mi[k1]=mi[l]; t[k1]=t[l]; se[k1]=min(se[l],mi[r]);
        mima[k1]=mima[l]; mise[k1]=mise[l]; tmi[k1]=tmi[l];
        update(sema[k1],sese[k1],tse[k1],mima[r],mise[r],tmi[r]);
    } else {
        mi[k1]=mi[r]; t[k1]=t[r]; se[k1]=min(se[r],mi[l]);
        mima[k1]=mima[r]; mise[k1]=mise[r]; tmi[k1]=tmi[r];
        update(sema[k1],sese[k1],tse[k1],mima[l],mise[l],tmi[l]);
    }
    update(sema[k1],sese[k1],tse[k1],sema[l],sese[l],tse[l]);
    update(sema[k1],sese[k1],tse[k1],sema[r],sese[r],tse[r]);
}
void addA(int k1,int k2){
    A[k1]+=k2; mi[k1]+=k2; sum[k1]+=1ll*t[k1]*k2;
}
void addB(int k1,int k2){
    B[k1]+=k2; if (abs(se[k1])!=inf) se[k1]+=k2; sum[k1]+=1ll*(size[k1]-t[k1])*k2;
}
void addC(int k1,int k2){
    C[k1]+=k2; mima[k1]+=k2; tot[k1]+=1ll*tmi[k1]*k2;
}
void addD(int k1,int k2){
    D[k1]+=k2; if (abs(mise[k1])!=inf) mise[k1]+=k2; tot[k1]+=1ll*(t[k1]-tmi[k1])*k2;
}
void addE(int k1,int k2){
    E[k1]+=k2; if (abs(sema[k1])!=inf) sema[k1]+=k2; tot[k1]+=1ll*tse[k1]*k2; 
}
void addF(int k1,int k2){
    F[k1]+=k2; if (abs(sese[k1])!=inf) sese[k1]+=k2; tot[k1]+=1ll*(size[k1]-t[k1]-tse[k1])*k2;
}
void pushdown(int k1){
    int l=k1*2,r=k1*2+1,num=min(mi[l],mi[r]),prenum=-inf,prenum2=max(sema[l],sema[r]);
    if (mi[l]==num) prenum=max(prenum,mima[l]); else prenum2=max(prenum2,mima[l]); 
    if (mi[r]==num) prenum=max(prenum,mima[r]); else prenum2=max(prenum2,mima[r]);
    if (mi[l]==num){
        addA(l,A[k1]); addB(l,B[k1]); 
        if (mima[l]==prenum) addC(l,C[k1]); else addC(l,D[k1]); 
        addD(l,D[k1]);
        if (sema[l]==prenum2) addE(l,E[k1]); else addE(l,F[k1]);
        addF(l,F[k1]); 
    } else {
        addA(l,B[k1]); addB(l,B[k1]);
        if (mima[l]==prenum2) addC(l,E[k1]); else addC(l,F[k1]);
        addD(l,F[k1]);
        if (sema[l]==prenum2) addE(l,E[k1]); else addE(l,F[k1]);
        addF(l,F[k1]);
    }
    if (mi[r]==num){
        addA(r,A[k1]); addB(r,B[k1]); 
        if (mima[r]==prenum) addC(r,C[k1]); else addC(r,D[k1]); 
        addD(r,D[k1]);
        if (sema[r]==prenum2) addE(r,E[k1]); else addE(r,F[k1]);
        addF(r,F[k1]); 
    } else {
        addA(r,B[k1]); addB(r,B[k1]);
        if (mima[r]==prenum2) addC(r,E[k1]); else addC(r,F[k1]);
        addD(r,F[k1]);
        if (sema[r]==prenum2) addE(r,E[k1]); else addE(r,F[k1]);
        addF(r,F[k1]);
    }
    A[k1]=0; B[k1]=0; C[k1]=0; D[k1]=0; E[k1]=0; F[k1]=0;
}
void buildtree(int k1,int k2,int k3){
    size[k1]=k3-k2+1;
    if (k2==k3){
        read(mi[k1]); assert(abs(mi[k1])<=1000000000); se[k1]=inf; mima[k1]=0; mise[k1]=-inf;  
        sema[k1]=-inf; sese[k1]=-inf; t[k1]=1; tmi[k1]=1; tse[k1]=0;
        sum[k1]=mi[k1]; tot[k1]=0; return;
    }
    int mid=k2+k3>>1;
    buildtree(k1*2,k2,mid); buildtree(k1*2+1,mid+1,k3);
    change(k1);
}
void down2(int k1,int k2,int k3,int k4){
    if (mima[k1]<=k4&&sema[k1]<=k4) return;
    if (mise[k1]<k4&&sese[k1]<k4){
        if (mima[k1]>k4){
            int now=k4-mima[k1]; addC(k1,now);
        }
        if (sema[k1]>k4){
            int now=k4-sema[k1]; addE(k1,now);
        }
        return;
    }
    int mid=k2+k3>>1; pushdown(k1);
    down2(k1*2,k2,mid,k4); down2(k1*2+1,mid+1,k3,k4);
    change(k1);
}
void add(int k1,int k2,int k3,int k4,int k5,int k6){
    if (k2>k5||k3<k4) return;
    if (k2>=k4&&k3<=k5){
        addA(k1,k6); addB(k1,k6); addC(k1,-k6); addD(k1,-k6); addE(k1,-k6); addF(k1,-k6);
        down2(k1,k2,k3,0); return;
    }
    pushdown(k1); int mid=k2+k3>>1;
    add(k1*2,k2,mid,k4,k5,k6);
    add(k1*2+1,mid+1,k3,k4,k5,k6);
    change(k1);
}
void down1(int k1,int k2,int k3,int k4){
    if (mi[k1]>=k4) return;
    if (se[k1]>k4){
        int now=k4-mi[k1]; addA(k1,now); addC(k1,-now); addD(k1,-now); return;
    }
    int mid=k2+k3>>1; pushdown(k1);
    down1(k1*2,k2,mid,k4); down1(k1*2+1,mid+1,k3,k4);
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
int findmin(int k1,int k2,int k3,int k4,int k5){
    if (k2>k5||k3<k4) return inf;
    if (k2>=k4&&k3<=k5) return mi[k1];
    int mid=k2+k3>>1; pushdown(k1);
    return min(findmin(k1*2,k2,mid,k4,k5),findmin(k1*2+1,mid+1,k3,k4,k5));
}
long long findsum(int k1,int k2,int k3,int k4,int k5){
    if (k2>k5||k3<k4) return 0;
    if (k2>=k4&&k3<=k5) return sum[k1]+tot[k1];
    int mid=k2+k3>>1; pushdown(k1);
    return findsum(k1*2,k2,mid,k4,k5)+findsum(k1*2+1,mid+1,k3,k4,k5);
}
void print(int k1,int k2,int k3){
//  cout<<"print "<<k1<<" "<<k2<<" "<<k3<<endl;
//  cout<<"fa "<<mi[k1]<<" "<<se[k1]<<" "<<t[k1]<<endl;
//  cout<<"mi "<<mima[k1]<<" "<<mise[k1]<<" "<<tmi[k1]<<endl;
//  cout<<"se "<<sema[k1]<<" "<<sese[k1]<<" "<<tse[k1]<<endl;
//  cout<<endl<<endl;
    if (k2==k3) return;
    int mid=k2+k3>>1; pushdown(k1); 
    int a=mi[k1],b=se[k1],c=mima[k1],d=mima[k2],e=sema[k1],f=sese[k1],g=sum[k1],h=tot[k1];
    print(k1*2,k2,mid); print(k1*2+1,mid+1,k3);
    change(k1);
    if (sum[k1]!=g||tot[k1]!=h) cout<<"fa"<<endl;
}
int main(){
    //freopen("data1.in","r",stdin);
    //freopen("data1.out","w",stdout);
    read(n); read(m);
    buildtree(1,1,n);
    for (;m;m--){
        int k1,k2,k3,k4; read(k1); read(k2); read(k3);
        assert(k2<=k3);
        if (k1==1){
            read(k4); assert(abs(k4)<=10000); add(1,1,n,k2,k3,k4);
        } else if (k1==2){
            read(k4); assert(abs(k4)<=1000000000); getmax(1,1,n,k2,k3,k4);
        } else println(findsum(1,1,n,k2,k3));
    //  print(1,1,n);
    }
    return 0;
}
