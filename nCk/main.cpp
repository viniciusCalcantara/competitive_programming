// References used in this code:
// https://codeforces.com/blog/entry/78873
// https://cp-algorithms.com/combinatorics/binomial-coefficients.html#computing-binomial-coefficients-modulo-m:~:text=operations%20are%20used.-,Binomial%20coefficient%20modulo%20large%20prime,-%C2%B6
#include <bits/stdc++.h>
#define fir first
#define sec second
#define pi pair<int, int>
#define MAXN 4'000'010
#define mod 998'244'353

using namespace std;
using ll = long long;

ll fact[MAXN];

void calc()
{   
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fact[i] = fact[i - 1] * i % mod;
}

ll powmodp(ll a, ll b, ll p)
{
    a %= p;
    if (a == 0)
        return 0;

    ll product = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            product *= a;
            product %= p;
            b--;
        }
        a *= a;
        a %= p;
        b >>= 1;
    }
    return product;
}

ll inv(ll a, ll p) { return powmodp(a, p - 2, p); }

ll nCk(ll n, ll k, ll p)
{
    return fact[n] * inv(fact[k] * fact[n - k] % p, p) % p;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    calc(); // precompute the factorials O(MAXN)
    
    cout << nCk(4, 2, mod) << "\n"; // compute nCk % p in O(log p)
    return 0;
}