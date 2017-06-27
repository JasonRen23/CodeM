#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;
int T;
LL a,b,c,k;
LL gcd(LL a,LL b)
{return b?gcd(b,a%b):a;}

int main()
{
	for(scanf("%d",&T);T--;)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
		if(c%gcd(b,gcd(a,k-1))==0)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}