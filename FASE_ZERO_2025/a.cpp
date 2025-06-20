#include <bits/stdc++.h>
#define MAXN 4'000'010
#define mod 998'244'353

using namespace std;
using ll = long long;

bool is_palindrome(ll n)
{
    ll m = 0;

    for (ll tmp = n; tmp; tmp >>= 1)
        m = (m << 1) | (tmp & 1);

    return m == n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x;
    cin >> x;

    ll aux = x;
    int cont = 0;
    while (aux)
    {
        aux >>= 1;
        cont++;
    }

    int l = cont / 2;
    aux = x;
    for (int i = 0; i < l; i++)
    {
        
    }

    //     string ans = "";
    //     while (aux)
    //     {
    //         if (aux & 1)
    //             ans += '1';
    //         else
    //             ans += '0';
    //     }

    //     for ()
    // }

    // cout << cont1 << "\n";
    return 0;
}
