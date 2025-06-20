#include <bits/stdc++.h>

#define MAXN 1'000'020

using namespace std;
using ll = long long;

int solve(int x, int m, vector<int> &v)
{
    for (int d = m; d <= x; d++)
    {
        if (x % d == 0)
        {
            int curr = 0;
            int flag = 0;
            for (int &e : v)
            {
                curr += e;
                if (curr > d)
                {
                    flag = 1;
                    break;
                }
                else if (curr == d)
                {
                    curr = 0;
                }
            }
            if (flag)
                continue;
            
            return d;
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("balancing.in", "r", stdin);
    // freopen("balancing.out", "w", stdout);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int &x : v)
            cin >> x;

        int cont = 0, x = v[0];
        for (int i = 0; i < n; i++)
        {
            if (v[i] == x)
                cont++;
        }

        if (cont == n)
        {
            cout << 0 << "\n";
        }
        else
        {
            int m = 0, acc = 0;
            for (int i = 0; i < n; i++)
            {
                acc += v[i];
                if (v[i] > m)
                    m = v[i];
            }

            int div = solve(acc, m, v);
            if (div == -1)
            {
                cout << n - 1 << "\n";
            }
            else
            {
                cout << n - (acc / div) << "\n";
            }
        }
    }
    return 0;
}