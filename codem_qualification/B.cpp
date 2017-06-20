#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[1<<20];
int main()
{
    int n,cnt=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]),cnt+=(a[i]<=a[0]);
    int r=-1;
    while(cnt)cnt>>=1,r++;
    printf("%d\n",r);
    return 0;
}
