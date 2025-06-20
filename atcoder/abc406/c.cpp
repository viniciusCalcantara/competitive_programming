#include <bits/stdc++.h>
#define fir first
#define sec second
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pi pair<int, int>
#define MAXN 4'000'010
#define mod 998'244'353

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    vii vv;
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] < v[i + 1])
        {
            if (vv.size() && vv.back().first == 0) vv.back().second++;
            else vv.emplace_back(0, 1);
        }
        else
        {
            if (vv.size() && vv.back().first == 1) vv.back().second++;
            else vv.emplace_back(1, 1);
        }
    }

    ll ans = 0;
    for (int i = 1; i < (int)vv.size() - 1; i++)
    {
        if (vv[i].first == 1)
        {
            ans += (ll) vv[i - 1].second * vv[i + 1].second;
        }
    }

    cout << ans << "\n";
    return 0;   
}
