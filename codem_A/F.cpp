#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
const int N = (int) 1e7;
const int mod = (int) 1e9 + 7;
using namespace std;
long long fac[N+10], inv[N+10], a[N+10];
int n;
long long ex(int x, int y, int w) {
    if ((w = (w + y) % y) % x == 0)
        return w / x;
    return ((ex(y % x, x, -w) * y) + w) / x;
}
long long c(int n, int m) {
    return (long long) fac[n] * inv[m] % mod * inv[n - m] % mod;
}
int main() {
    cin >> n;
    fac[0] = 1;
    for (int i = 1; i <= n; ++i)
        fac[i] = fac[i-1] * (long long) i % mod;
    inv[n] = ex(fac[n], mod, 1);
    for (int i = n; i >= 1; --i)
        inv[i-1] = (long long) inv[i] * i % mod;
    a[0] = 1;
    for (int i = 1; i <= n; ++i)
        a[i] = (2LL * i * a[i - 1] % mod - ((long long) (i-1) * (i-1)) % mod * a[i - 2] % mod + mod) % mod;
    long long ans = 0;
    for (int i = 0; i <= n; ++i)
        ans = (ans + ((i & 1 ? mod - 1LL : 1LL) * c(n, i) % mod * c(n, i) % mod * fac[i] % mod * a[n-i] % mod * a[n-i] % mod)) % mod;
    cout << ans << endl;
}