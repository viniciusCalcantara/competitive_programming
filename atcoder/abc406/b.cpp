
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n, k;
    cin >> n >> k;
    ll x = 1, y = 1;

    for (int i = 0; i < k; i++)
        y *= 10;
    y--;

    ll a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (x > y / a) x = 1;
        else x *= a;
    }
    cout << x << "\n";
}