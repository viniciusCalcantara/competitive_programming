#include <bits/stdc++.h>
#define MAXN 200'020
using namespace std;

struct DSU {
    vector<int> parent, rank;

    DSU(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void join(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
};

int main() 
{
    int n, m; cin >> n >> m;
    DSU dsu(n);

    while (m--)
    {
        int op; cin >> op;

        if (op == 1)
        {
            int u, v; cin >> u >> v;
            dsu.join(u, v);
        }
        else
        {
            int u; cin >> u;
            dsu.find(u);
        }
    }
    return 0;
}