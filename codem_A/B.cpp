#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int T;
int n,m;
char a[55],b[55];
bool f[55][55][55][55];
int main()
{
  for(scanf("%d",&T);T--;)
  {
    scanf("%s",a+1);n=strlen(a+1);
    scanf("%s",b+1);m=strlen(b+1);
    int ans=0;
    for(int d1=0;d1<=n;d1++)
      for(int d2=0;d2<=m;d2++)
        for(int i=1,j=d1;j<=n;i++,j++)
          for(int k=1,l=d2;l<=m;k++,l++)
          {
            if(d1+d2<=1)f[i][j][k][l]=1;
            else
            {
              f[i][j][k][l]=0;
              if(d1>1&&a[i]==a[j])f[i][j][k][l]|=f[i+1][j-1][k][l];
              if(d1&&d2&&a[i]==b[l])f[i][j][k][l]|=f[i+1][j][k][l-1];
              if(d1&&d2&&b[k]==a[j])f[i][j][k][l]|=f[i][j-1][k+1][l];
              if(d2>1&&b[k]==b[l])f[i][j][k][l]|=f[i][j][k+1][l-1];
            }
            if(f[i][j][k][l])ans=max(ans,d1+d2);
          }
    printf("%d\n",ans);
  }
  return 0;
}