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
const double pi=acos(-1);
VI E[N];
int dep[N],fa[N],ans,n,f[N],k[N],p[N];
void dfs(int x){
	f[x]=dep[x]-k[x]+1;
	p[x]=1e9;
	for(int i=0;i<E[x].size();++i){
		dep[E[x][i]]=dep[x]+1;
		dfs(E[x][i]);
		f[x]=min(f[x],f[E[x][i]]);
		p[x]=min(p[x],p[E[x][i]]);
	}
	if(p[x]>dep[x]){
		ans++;
		p[x]=f[x];
	}
}
int main(int argv,char **argc){
//	freopen("in","r",stdin);
//	freopen("out","w",stdout);
	freopen(argc[1],"r",stdin);
	freopen(argc[2],"w",stdout);
	scanf("%d",&n);
	rep(i,2,n){
		scanf("%d",&fa[i]);
		E[fa[i]].pb(i);
	}
	dep[1]=1;
	rep(i,1,n)scanf("%d",&k[i]);
	dfs(1);
	cerr<<ans<<endl;
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}