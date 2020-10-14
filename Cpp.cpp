#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define debug(x) cout << #x << " = " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
inline ll Mod(ll x, ll mod) { return x % mod >= 0 ? x % mod : x % mod + mod; }

template <typename T>
T power(T x, T y, T n)
{
    x %= n;
    T ans = 1;
    while (y > 0)
    {
        if (y & 1 == 1)
        {
            ans = ans * x % n;
        }
        x = x * x % n;
        y >>= 1;
    }
    return (ans);
}

template <typename T>
T solve(T a, T b, T m)
{
    a %= m, b %= m;
    T k = 1, add = 0, g;
    while ((g = __gcd(a, m)) > 1)
    {
        if (b == k)
            return add;
        if (b % g)
            return -1;
        b /= g, m /= g, add++;
        k = (k * 1ll * a / g) % m;
    }

    T n = sqrt(m) + 1;
    T an = power(a, n, m);

    unordered_map<T, T> vals;
    for (T q = 0, cur = b; q <= n; q++)
    {
        vals[cur] = q;
        cur = (cur * 1ll * a) % m;
    }

    for (T p = 1, cur = k; p <= n; p++)
    {
        cur = (cur * 1ll * an) % m;
        if (vals.count(cur))
        {
            T ans = n * p - vals[cur] + add;
            return ans;
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
