#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <algorithm>
#define L 100
using namespace std;
int n,m,S,Sn,i,j,k,w,l,r,u,v,ul,vr,c;
int a[50005],sum[50000/L+5][50005],ans[50005],t[50005];
int ql[50005],qr[50005],qk[50005];
vector<int> V[100005];
vector<pair<int,int> > Ins[L+5][50005],Del[L+5][50005];
vector<int> query[50005];
int main()
{
  scanf("%d%d",&n,&m);S=min((int)sqrt(n),100);
  for(i=1;i<=n;++i)scanf("%d",&a[i]),V[a[i]].push_back(i);
  
  for(i=1;i<=n;++i)
  if(V[i].size()>=S)
  {
    ++Sn;
    for(k=V[i].size(),j=0;j<k;++j)++sum[Sn][V[i][j]];
    for(j=1;j<=n;++j)sum[Sn][j]+=sum[Sn][j-1];
  }
  else
  {
    c=V[i].size();
    for(j=0;j<c;++j)
    {
      u=V[i][j];
      if(j)ul=V[i][j-1]+1;else ul=1;
      for(k=j,l=1;k<c;++k,++l)
      {
        v=V[i][k];
        if(k<c-1)vr=V[i][k+1]-1;else vr=n;
        Ins[l][ul].push_back(make_pair(v,vr));
        Del[l][u].push_back(make_pair(v,vr));
      }
    }
  }
  
  for(i=1;i<=m;++i)
  {
    scanf("%d%d%d",&ql[i],&qr[i],&qk[i]);
    l=ql[i];r=qr[i];
    query[l].push_back(i);
    for(j=1;j<=Sn;++j)if(sum[j][r]-sum[j][l-1]>0&&__gcd(sum[j][r]-sum[j][l-1],qk[i])==1)++ans[i];
  }
  
  for(i=1;i<S;++i)
  for(j=1;j<=n;++j)
  {
    for(k=Ins[i][j].size()-1;k>=0;--k)
    {
      l=Ins[i][j][k].first;
      r=Ins[i][j][k].second;
      for(w=l;w<=n;w+=w&-w)++t[w];
      for(w=r+1;w<=n;w+=w&-w)--t[w];
    }
    for(k=query[j].size()-1;k>=0;--k)
    {
      l=query[j][k];
      u=qr[l];v=qk[l];
      if(__gcd(v,i)!=1)continue;
      for(w=u;w;w-=w&-w)ans[l]+=t[w];
    }
    for(k=Del[i][j].size()-1;k>=0;--k)
    {
      l=Del[i][j][k].first;
      r=Del[i][j][k].second;
      for(w=l;w<=n;w+=w&-w)--t[w];
      for(w=r+1;w<=n;w+=w&-w)++t[w];
    }
  }
  
  for(i=1;i<=m;++i)printf("%d\n",ans[i]);
}