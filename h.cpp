#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> dp;
vector<int> flag;

ll dfs(int u, const vector<ll> &a, vector<vector<int>> &grafo)
{
    ll res = a[u];
    for (int v : grafo[u])
    {
        res += dfs(v, a, grafo);
    }
    return dp[u] = res;
}

ll solve(int u, vector<vector<int>> &grafo)
{
    ll aux = 0;
    for (int v : grafo[u])
    {
        aux += solve(v, grafo);
    }

    if (aux > dp[u])
        return aux;
    return dp[u];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    vector<vector<int>> grafo(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 1; i < n; i++)
    {
        int u;
        cin >> u;
        u--;
        grafo[u].push_back(i);
    }

    dp.assign(n, 0);

    dfs(0, a, grafo);
    cout << solve(0, grafo) << "\n";
    return 0;
}
