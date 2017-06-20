#include<bits/stdc++.h>
#define int64 long long
#define sqr(x) (x)*(x)
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define VI vector<int>
#define VI64 vector<int64>
#define VS vector<string>
#define PII pair<int,int>
#define PDD pair<double,double>
#define VPII vector< PII >
#define SZ(x) ((int)(x).size())
#define N 120000
using namespace std;
int n,t[N],c[N];
int T,C;
void P(double x){
	printf("Possible\n");
	printf("%.4lf\n",x);
	exit(0);
}
void fail(){
	printf("Impossible\n");
	exit(0);
}
int main(int argv,char **argc){
freopen(argc[1],"r",stdin);
freopen(argc[2],"w",stdout);
	scanf("%d",&n);
	scanf("%d%d",&T,&C);
	cerr<<C<<endl;
	bool f1=0,f2=0;
	rep(i,1,n){
		scanf("%d%d",&t[i],&c[i]);
		if(t[i]<T)f1=1;
		if(t[i]>T)f2=1;
	}
	if(f1 && f2)fail();
	if(!f1 && !f2)P(T);
	if(f1){
		T*=-1;
		rep(i,1,n)t[i]*=-1;
	}
	int minnT=1e9;
	int64 cc=0;
	rep(i,1,n)minnT=min(minnT,t[i]);
	if(minnT==T)fail();
	rep(i,1,n)cc+=(minnT*c[i]-c[i]*t[i]);
	if(T-minnT>0 && cc>(int64)C*(T-minnT))fail();
	if(T-minnT<0 && cc<(int64)C*(T-minnT))fail();
	cerr<<"lucky"<<endl;
	if(f1){
		double f1=0,f2=0;
		f1=(double)T*C;
		f2=C;
		rep(i,1,n)f1+=t[i]*c[i],f2+=c[i];
		P(-f1/f2);
	}else P(minnT*(f1?-1:1));
	return 0;
}