
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> g;
vector<bool> vis;

void dfs(int v)
{
    vis[v] = true;
    for (int u : g[v])
    {
        if (!vis[u])
        {
            dfs(u);
        }
    }
    return;
}

int main()
{
    cin >> n >> m;
    g = vector<vector<int>>(n);
    vis = vector<bool>(n, false);

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        g[--a].push_back(--b);
        g[b].push_back(a);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            ans++;
            dfs(i);
        }
    }
    cout << ans << "\n";
    return 0;
}