#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1005;
const int INF=0x3f3f3f3f;//表示无穷大
int a[MAXN],b[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    int res=INF;
    for(int i=0;i+n<=m;i++)
    {
        int now=0;
        for(int j=1;j<=n;j++)
            now+=(a[j]-b[i+j])*(a[j]-b[i+j]);
        res=min(res,now);
    }
    printf("%d\n",res);
    return 0;
}
