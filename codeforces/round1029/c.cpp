#include <bits/stdc++.h>

#define MAXN 200'010

using namespace std;
using ll = long long;

void solve(int n, vector<int> &v)
{
    for (int &x : v) cin >> x;
    set<int> s = {v[0]}, s_aux, match;
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        s_aux.insert(v[i]);
        if (s.find(v[i]) != s.end())
        {
            match.insert(v[i]);
            if (match.size() == s.size())
            {
                ans++;
                s = s_aux;
                s_aux.clear();
                match.clear();
            }
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        solve(n, v);
    }
    return 0;
}