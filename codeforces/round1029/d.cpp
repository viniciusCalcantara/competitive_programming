#include <bits/stdc++.h>

#define int long long
#define MAXN 200'010
using namespace std;

pair<int, int> solve(int n, int a1, int an)
{
    int a = (an - (n * a1)), b = (1 - n * n);
    int y = a / b;
    if (b * y == a)
    {
        int x = a1 - n * y;
        if (y >= 0 && x >= 0)
            return {x, y};
    }
    return {-1, -1};
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n + 1);
        int acc = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
            acc += v[i];
        }

        auto [x, y] = solve(n, v[1], v[n]);
        if (x == -1 && y == -1)
        {
            cout << "NO\n";
        }
        else
        {
            int possible = 1;
            for (int i = 2; i <= n - 1; i++)
            {
                if (x * i + y * (n - i + 1) != v[i])
                {
                    possible = 0;
                    break;
                }
            }
            cout << (possible ? "YES\n" : "NO\n");
        }
    }
    return 0;
}