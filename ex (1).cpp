#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> dp;

ll dfs(int u, const vector<ll> &a, vector<vector<int>> &grafo) {
    ll res = a[u];
    for (int v : grafo[u]) {
        ll sub = dfs(v, a, grafo);
        if (sub > 0)
            res += sub;
    }
    dp[u] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    vector<vector<int>> grafo(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 1; i < n; i++) {
        int u;
        cin >> u;
        u--;
        grafo[u].push_back(i);
    }

    dp.assign(n, 0);  

    ll ans = dfs(0, a, grafo);

    for (int i = 0; i < n; i++)
        cout << dp[i] << ' ';
    cout << "\n";

    
    cout << max(ans, 0LL) << endl;

    return 0;
}
