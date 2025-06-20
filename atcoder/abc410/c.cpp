#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = i + 1;
    }

    int op;
    int k = 0;
    while (q--)
    {
        cin >> op;
        if (op == 1)
        {
            int p, x;
            cin >> p >> x;
            p--;
            v[(((p + k) % n) + n) % n] = x;
        }
        else if (op == 2)
        {
            int p;
            cin >> p;
            p--;
            cout << v[(((p + k) % n) + n) % n] << "\n";
        }
        else if (op == 3)
        {
            int inc;
            cin >> inc;
            k += inc;
        }
    }
    return 0;
}