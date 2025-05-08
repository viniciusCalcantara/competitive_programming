#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    ll maxEnd, ans; cin >> ans; maxEnd = ans;
    for (int i = 1; i < n; i++)
    {
        ll x;
        cin >> x;
        maxEnd = max(maxEnd + x, x);
        ans = max(maxEnd, ans);
    }
    cout << ans << "\n";
    return 0;
}