
#include <bits/stdc++.h>

using namespace std;

int n, m;

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
    cin >> n >> m;
    DSU d = DSU(n);

    int a, b, k = n;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        --a; --b;
        if (d.find(a) != d.find(b))
            k--;
        d.join(a, b);
    }

    cout << m - n + k << "\n";
    return 0;
}