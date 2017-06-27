#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 105
#define eps 0.00000001
#define For(i,l,r) for(int i=l;i<=r;i++)
#define Dor(i,r,l) for(int i=r;i>=l;i--)
int n,m,K;
int pt[maxn],h1[maxn],h2[maxn];
int son[maxn],Next[maxn*maxn/2],ed[maxn*maxn/2],wt[maxn*maxn/2],cnt;
double f[60*8+5][maxn];
double Doit(int *h){
	double result=0;
	For(t,0,K) For(now,1,n) f[t][now]=0;
	For(now,1,n) f[pt[now]][now]=1.0/n;
        For(t,0,K){
        	For(now,1,n) result+=f[t][now]*h[now];
        	For(now,1,n){
			int num=0;

			for(int i=son[now];i;i=Next[i])
			if(K-t>=wt[i]+pt[ed[i]]) num++;

			if(num==0) continue;

			for(int i=son[now];i;i=Next[i])
			if(K-t>=wt[i]+pt[ed[i]])
				f[t+wt[i]+pt[ed[i]]][ed[i]] += f[t][now]/num;
        	}
        }
        return result;
}
int main(){

	cin >> n >> m >> K;
	For(i,1,n) cin >> pt[i] >> h1[i] >> h2[i];
	For(i,1,m){
		int x, y, t;
		cin >> x >> y >> t;
		Next[++cnt]=son[x]; son[x]=cnt; ed[cnt]=y; wt[cnt]=t;
		Next[++cnt]=son[y]; son[y]=cnt; ed[cnt]=x; wt[cnt]=t;
	}
	printf("%.5lf %.5lf\n",Doit(h1),Doit(h2));
}