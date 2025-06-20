#include <bits/stdc++.h>

#define int long long
using namespace std;
using ll = long long;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int y, k;
    cin >> y >> k;
    ll x = 1;

    while (k--)
        x += gcd(x, y);

    cout << x << "\n";
    return 0;
}