#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=500005;
int CtI[256],T;
int n,m,a[maxn],b[maxn];
char str[maxn];
int cnt[maxn][4],pos[4][maxn];

struct node
{
	int s[16];
	node *lc,*rc;
	
	int Max(int l,int r,const int &a,const int &b,const int &mask)
	{
		if(l>=a&&r<=b)return s[mask];
		int mid=l+r>>1;
		if(b<=mid)return lc->Max(l,mid,a,b,mask);
		if(a>mid)return rc->Max(mid+1,r,a,b,mask);
		return max(lc->Max(l,mid,a,b,mask),rc->Max(mid+1,r,a,b,mask));
	}
	
}ndl[maxn*2],*ns,*root;

node* build(int l,int r)
{
	node *x=++ns;
	if(l==r)
	{
		for(int mask=0;mask<16;mask++)
		{
			x->s[mask]=0;
			for(int c=0;c<4;c++)
				x->s[mask]+=(mask>>c&1)?cnt[l][c]:-cnt[l][c];
		}
	}
	else
	{
		int mid=l+r>>1;
		x->lc=build(l,mid);
		x->rc=build(mid+1,r);
		for(int mask=0;mask<16;mask++)
			x->s[mask]=max(x->lc->s[mask],x->rc->s[mask]);
	}
	return x;
}

void init()
{
	CtI['A']=0,CtI['C']=1,CtI['G']=2,CtI['T']=3; 
	scanf("%s",str+1);n=strlen(str+1);
	for(int i=1;i<=n;i++)a[i]=CtI[str[i]];
	scanf("%s",str+1);m=strlen(str+1);
	for(int i=1;i<=m;i++)b[i]=CtI[str[i]];
	
	for(int i=1;i<=n;i++)
	{
		memcpy(cnt[i],cnt[i-1],sizeof(cnt[0]));
		cnt[i][a[i]]++;
		pos[a[i]][cnt[i][a[i]]]=i;
	}
	ns=ndl;
	root=build(0,n);
}

void work()
{
	int bA[4],bL[4];
	memset(bA,0,sizeof(bA));
	memset(bL,0,sizeof(bL));
	for(int i=1;i<=m;i++)
		bA[b[i]]++;
	int ans=0,sl[6],cu[6];
	for(int l,r,d,k,mask,i=0;i<=m;i++)
	{
		if(i)bL[b[i]]++;
		for(int c=0;c<4;c++)
		{
			k=bA[c]-bL[c]-bL[c]+cnt[n][c];
			if(k<0)k=(k-1)/2;
			else k/=2;
			k++;
			if(k<=0)k=-1;
			else if(k>cnt[n][c])k=n;
			else k=pos[c][k]-1;
			sl[c]=cu[c]=k;
		}
		sort(sl,sl+4);
		sl[5]=n;
		for(int j=0;j<=4;j++)
		{
			if(j==0)l=0;
			else l=sl[j-1]+1;
			r=sl[j];
			l=max(l,0),r=min(r,n);
			if(l<=r)
			{
				d=mask=0;
				for(int c=0;c<4;c++)
					if(r<=cu[c])d+=bL[c],mask|=1<<c;
					else d+=bA[c]-bL[c]+cnt[n][c];
				ans=max(ans,d+root->Max(0,n,l,r,mask));
			}
		}
	}
	printf("%d\n",ans);
}

int main()
{
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	for(scanf("%d",&T);T--;)
	{
		init();
		work();
	}
	return 0;
}