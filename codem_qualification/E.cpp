#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll get(ll n,ll m)
{
    if(n==0 || m==0)return 0;
    ll res=0,t=0;
    m=min(n,m);
    for(t=1;t<=m && t*t<=n;t++)
        res+=n/t;
    for(ll i=n/t;i>=n/m;i--)
        res+=(min(m,n/i)-n/(i+1))*i;
    return res;
}
ll sum(ll n,ll tl,ll tr)
{
    return get(n,tr)-get(n,tl-1);
}
ll cal(ll l,ll r,ll tl,ll tr)
{
    return sum(r,tl,tr)-sum(l-1,tl,tr);
}
ll pw[15],res[15];
int main()
{
    for(int i=(pw[0]=1);i<15;i++)
        pw[i]=10*pw[i-1];
    ll l,r;
    scanf("%lld%lld",&l,&r);
    for(int i=0;i<=9;i++)
        for(int j=1;j<=9;j++)
            res[j]+=cal(l,r,j*pw[i],(j+1)*pw[i]-1);
    for(int i=1;i<=9;i++)
        printf("%lld\n",res[i]);
    return 0;
}
