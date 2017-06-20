#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
typedef unsigned long long ull;
const int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char cur[25][25],nxt[25][25];
set<pair<ull,ull> > st;
inline void init()
{
    st.clear();
    for(int i=1;i<=19;i++)
        for(int j=1;j<=19;j++)
            cur[i][j]='.';
    for(int i=1;i<=19;i++)
        for(int j=1;j<=19;j++)
            nxt[i][j]='.';
}
inline void cop()
{
    for(int i=1;i<=19;i++)
        for(int j=1;j<=19;j++)
            nxt[i][j]=cur[i][j];
}
inline void pas()
{
    for(int i=1;i<=19;i++)
        for(int j=1;j<=19;j++)
            cur[i][j]=nxt[i][j];
}
inline bool check()
{
    ull has[2]={0,0};
    for(int i=1;i<=19;i++)
        for(int j=1;j<=19;j++)
        {
            has[0]=has[0]*131+nxt[i][j];
            has[1]=has[1]*137+nxt[i][j];
        }
    if(st.find(make_pair(has[0],has[1]))==st.end())
    {
        st.insert(make_pair(has[0],has[1]));
        return 1;
    }
    else return 0;
}
inline void show()
{
    for(int i=1;i<=19;i++)
        printf("%s\n",cur[i]+1);
}
int vis[25][25];
inline void fre()
{
    for(int i=1;i<=19;i++)
        for(int j=1;j<=19;j++)
            vis[i][j]=0;
}
bool dfs(int x,int y,char g)
{
    if(nxt[x][y]=='.')return 1;
    if(nxt[x][y]!=g)return 0;
    vis[x][y]=1;
    bool isok=0;
    for(int i=0;i<4;i++)
    {
        int tx=x+dir[i][0],ty=y+dir[i][1];
        if(!vis[tx][ty])
            isok|=dfs(tx,ty,g);
    }
    return isok;
}
void pick(int x,int y,char g)
{
    nxt[x][y]='.';
    for(int i=0;i<4;i++)
    {
        int tx=x+dir[i][0],ty=y+dir[i][1];
        if(nxt[tx][ty]==g)pick(tx,ty,g);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        init();
        check();
        for(int i=1;i<=n;i++)
        {
            char go[5];
            int x,y;
            scanf("%s%d%d",go,&x,&y);
            char a=go[0],b="BW"[a=='B'];
            if(cur[x][y]!='.')printf("miss 1\n");
            else
            {
                cop();
                nxt[x][y]=a;
                fre();
                bool isok=dfs(x,y,a);
                for(int i=0;i<4;i++)
                {
                    int tx=x+dir[i][0],ty=y+dir[i][1];
                    if(!vis[tx][ty] && nxt[tx][ty]==b && !dfs(tx,ty,b))
                    {
                        pick(tx,ty,b);
                        isok=1;
                    }
                }
                if(isok)
                {
                    if(check())pas();
                    else printf("miss 3\n");
                }
                else printf("miss 2\n");
            }
        }
        show();
    }
    return 0;
}
