#include <cstdio>
#include <algorithm>
#include <cstring>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
const int N = 1005;
int n;
double v, u, c[N], d[N];
int main(){
    scanf("%d%lf%lf",&n,&v,&u);
    rep(i,1,n) scanf("%lf",c+i);
    rep(i,1,n) scanf("%lf",d+i);
    double ans = 0;
    rep(i,1,n) rep(j,1,n) ans+=1.0/(c[i]-(j-1)*d[i]-v);
    ans*=u;
    printf("%.3lf\n",ans);
}