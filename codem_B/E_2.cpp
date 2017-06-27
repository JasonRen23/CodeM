#include <string>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

const int maxn = 1000000+10;

char t[maxn] = {0};
int n;

char change(int a)
{
    if(a<10)
    {
        return a + '0';
    }
    else
    {
        return a - 10 + 'A';
    }
}

bool judge(int k)
{
#include <string>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

const int maxn = 1000000+10;

char t[maxn] = {0};
int n;

char change(int a)
{
    if(a<10)
    {
        return a + '0';
    }
    else
    {
        return a - 10 + 'A';
    }
}

bool judge(int k)
{
    string s;
    for(int i=1; i<=n; i++)
    {
        int u = i;
        stack<int> st;
        while(u!=0)
        {
            st.push(u%k);
            u /= k;
        }
        while(!st.empty())
        {
            int temp = st.top();
            st.pop();
            s.push_back(change(temp));
        }
    }
//    cout << s << endl;
    if(s.find(t)!=string::npos)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    scanf("%d", &n);
    scanf("%s", t);
    int maxx = 0;
    for(int i=0; t[i]!='\0'; i++)
    {
        if(isdigit(t[i]))
        {
            maxx = max(maxx, t[i]-'0');
        }
        else
        {
            maxx = max(maxx, 10+t[i]-'A');
        }
    }
    bool ok = false;
    for(int i=maxx+1; i<=16; i++)
    {
        if(judge(i))
        {
            ok = true;
            break;
        }
    }
    printf("%s", ok?"yes":"no");
    return 0;
}