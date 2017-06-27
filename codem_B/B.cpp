#include <stdio.h>
#include <stdlib.h>
#define inf 1000000005
using namespace std;

int n,m,q,Q,i,j,k,u,v,c,ans;
int s[15],t[15],l[15],r[15],w[15],p[15];
int son[25],Next[405],ed[405],cost[405],tot;
int f[60005][25];
bool vis[25];

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(;m;--m)
	{
		scanf("%d%d%d",&u,&v,&c);
		++tot;Next[tot]=son[u];son[u]=tot;ed[tot]=v;cost[tot]=c;
	}
	for(i=Q=1;i<=q;++i,Q*=3)scanf("%d%d%d%d",&s[i],&t[i],&l[i],&r[i]),p[i]=Q;
	for(i=0;i<Q;++i)
	for(j=1;j<=n;++j)
	f[i][j]=inf;
	f[0][1]=0;
	for(i=0;i<Q;++i)
	{
		for(j=1;j<=n;++j)vis[j]=false;
		for(j=1;j<=n;++j)
		{
			for(u=0,k=1;k<=n;++k)if(!vis[k]&&(!u||f[i][k]<f[i][u]))u=k;
			for(k=son[u],vis[u]=true;k;k=Next[k])if(f[i][u]+cost[k]<f[i][ed[k]])f[i][ed[k]]=f[i][u]+cost[k];
		}
		for(j=1,k=i;j<=q;++j,k/=3)w[j]=k%3;
		for(v=0,j=1;j<=q;++j)
		{
			if(w[j]==0&&f[i][s[j]]<inf)
			{
				if(f[i][s[j]]>l[j])u=f[i][s[j]];else u=l[j];
				if(u<f[i+p[j]][s[j]])f[i+p[j]][s[j]]=u;
			}
			if(w[j]==1&&f[i][t[j]]<=r[j])
			{
				u=f[i][t[j]];
				if(u<f[i+p[j]][t[j]])f[i+p[j]][t[j]]=u;
			}
			if(w[j]==2)++v;
		}
		for(j=1;j<=n;++j)if(f[i][j]<inf&&v>ans)ans=v;
	}
	printf("%d\n",ans);
}