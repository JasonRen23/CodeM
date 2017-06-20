#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int ok[MAXN],vis[MAXN];
vector<int> go[MAXN],rg[MAXN];
void dfs1(int u)
{
    ok[u]=1;
    for(int i=0;i<(int)rg[u].size();i++)
    {
        int v=rg[u][i];
        if(!ok[v])dfs1(v);
    }
}
vector<int> res;
void dfs2(int u,int t)
{
    if(u==t)
    {
        for(int i=0;i<(int)res.size();i++)
            printf("%c",res[i]+'a');
        exit(0);
    }
    vis[u]=1;
    for(int i=0;i<(int)go[u].size();i++)
    {
        int v=go[u][i];
        if(v<0 || !ok[v])continue;
        if(vis[v])
        {
            printf("Infinity!\n");
            exit(0);
        }
        res.push_back(i);
        dfs2(v,t);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int _=0;_<2;_++)
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            int t=i+a;
            if(t>=0 && t<n)
            {
                go[i].push_back(t);
                rg[t].push_back(i);
            }
            else go[i].push_back(-1);
        }
    dfs1(n-1);
    if(!ok[0])return 0*printf("No solution!\n");
    dfs2(0,n-1);
    return 0;
}
