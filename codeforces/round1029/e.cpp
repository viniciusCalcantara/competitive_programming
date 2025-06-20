#include <bits/stdc++.h>

#define MAXN 200'010
#define int long long
using namespace std;
using ll = long long;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        vector<vector<int>> v(n + 1);
        vector<int> f1(n + 1);
        for (int i = n - 1; i >= 0; i--)
        { 
            f1[a[i]]++;
            if (f1[a[i]] == 1)
            {
                v[i].push_back(i);
            }
        }
        
        vector<int> f2(n + 1);
        for (int i = n - 1; i >= 0; i--)
        { 
            f2[b[i]]++;
            if (f2[b[i]] == 1)
            {
                v[i].push_back(i);
            }
        }

        sort(v.begin(), v.end());
        
        int ans = 0;
        for (int i = v.size() - 1; i >= 0; i--)
        {
            if (v[i].size() == 2 && abs(v[i][0] - v[i][1]) % 2 == 0)
            {
                int m = INT_MAX;
                m = min(v[i][0], v[i][1]);
                ans = m;
            }
        }

        cout << ans << "\n";
        
    }
    return 0;
}