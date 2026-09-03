#include <bits/stdc++.h>

#define pb push_back
#define MAXN 2000

using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  int aux = t;
  while (aux--)
  {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    int u, v;
    for (int i = 0; i < m; i++)
    {
      cin >> u >> v;
      u--, v--;
      adj[u].pb(v);
      adj[v].pb(u);
    }

    vector<int> side(n, -1);
    bool is_bipartite = true;
    queue<int> q;
    for (int st = 0; st < n; ++st)
    {
      if (side[st] == -1) {
        q.push(st);
        side[st] = 0;
        while (!q.empty())
        {
          int v = q.front();
          q.pop();
          for (int u : adj[v])
          {
            if (side[u] == -1)
            {
              side[u] = side[v] ^ 1;
              q.push(u);
            }
            else
            {
              is_bipartite &= side[u] != side[v];
            }
          }
        }
      }
    }

    cout << "Scenario #" << t - aux << ":\n";
    if (is_bipartite) cout << "No suspicious bugs found!";
    else cout << "Suspicious bugs found!";
    cout << "\n";
  }
  return 0;
}
