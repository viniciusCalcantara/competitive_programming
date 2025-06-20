#include <bits/stdc++.h>
#define MAXN 200'020
using namespace std;

struct DSU
{
    vector<int> parent, rank;

    DSU(int n) : parent(n), rank(n, 0)
    {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void join(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return;
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
};

bool there_is_a_walk(vector<tuple<int, int, int>> &edges, int n)
{
    DSU dsu(n);
    for (auto &[a, b, c] : edges)
        dsu.join(a, b);

    if (dsu.find(0) != dsu.find(n - 1))
        return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges(m);
    vector<int> f(30, 0);
    for (auto &[a, b, c] : edges)
    {
        cin >> a >> b >> c;
        a--;
        b--;

        for (int i = 29; i >= 0; i--)
        {
            f[i] += (c >> i) & 1;
        }
    }

    for (int i = 0; i <= 2; i++)
        cout << i << " : " << f[i] << "\n";

    if (!there_is_a_walk(edges, n))
    {
        cout << -1 << "\n";
    }
    else
    {
        int ans = 0;
        for (int i = 29; i >= 0; i--)
        {
            DSU dsu(n);
            for (auto &[a, b, c] : edges)
            {
                if (f[i] % 2 == 1)
                    continue;

                dsu.join(a, b);
            }

            if (dsu.find(0) != dsu.find(n - 1))
                ans |= 1 << i;
        }
        cout << ans << "\n";
    }

    return 0;
}