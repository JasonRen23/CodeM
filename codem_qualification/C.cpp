#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
const int MAXN=100005;
int cnt[MAXN],la[MAXN];
int main()
{
    int m;
    scanf("%d",&m);
    set<int> mark;
    for(int i=1;i<=m;i++)
    {
        char ty[5];
        scanf("%s",ty);
        if(*ty!='?')
        {
            int x;
            scanf("%d",&x);
            cnt[x]+=(*ty=='I' ? 1 : -1);
            if(cnt[x]<0 || cnt[x]>1)
            {
                if(mark.lower_bound(la[x])==mark.end())
                    return 0*printf("%d\n",i);
                mark.erase(mark.lower_bound(la[x]));
                cnt[x]=min(max(cnt[x],0),1);
            }
            la[x]=i;
        }
        else mark.insert(i);
    }
    return 0*printf("-1\n");
}
