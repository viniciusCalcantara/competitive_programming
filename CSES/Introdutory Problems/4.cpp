#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &x : v)
        cin >> x;

    ll ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int dif = v[i] - v[i + 1];
        if (dif > 0)
        {
            ans += dif;
            v[i + 1] = v[i];
        }
    }

    cout << ans << "\n";
    return 0;
}