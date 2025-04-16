#include <bits/stdc++.h>
#define MAXN 200'020
using namespace std;

vector<int> parent(MAXN);
vector<int> depth(MAXN);

void dsu_setup(int n)
{
    for (int v = 0; v < n; v++)
    {
        parent[v] = v;
        depth[v] = 0;
    }
}

int dsu_find(int v)
{
    if (v == parent[v])
    {
        return v;
    }
    return parent[v] = dsu_find(parent[v]);
}

void dsu_union(int a, int b)
{
    a = dsu_find(a);
    b = dsu_find(b);
    if (a != b)
    {
        if (depth[a] < depth[b])
            swap(a, b);

        parent[b] = a;
        if (depth[a] == depth[b])
            depth[a]++;
    }
}

int main() 
{
    // setup do DSU
    int n, m; cin >> n >> m;
    dsu_setup(n);

    while (m--)
    {
        int op; cin >> op;

        if (op == 1)
        {
            int u, v; cin >> u >> v;
            dsu_union(u, v);
        }
        else
        {
            int u; cin >> u;
            dsu_find(u);
        }
    }
    return 0;
}