#include <bits/stdc++.h>
#define pi pair<int, int>

using namespace std;
using ll = long long;

int n;
vector<char> d;
vector<pi> cow;

bool fe(int a, int b) { return cow[a].second < cow[b].second; }
bool fn(int a, int b) { return cow[a].first < cow[b].first; }
void solve()
{
    vector<int> cowe, cown;
    for (int i = 0; i < n; i++)
    {
        if (d[i] == 'E')
            cowe.push_back(i);
        else
            cown.push_back(i);
    }

    sort(cowe.begin(), cowe.end(), fe);
    sort(cown.begin(), cown.end(), fn);

    int inf = 1e9 + 1;
    vector<int> ans(n, inf);

    for (int cei : cowe)
    {
        auto [xe, ye] = cow[cei];
        for (int cni : cown)
        {
            auto [xn, yn] = cow[cni];
            int dx = xn - xe;
            int dy = ye - yn;
            if (dx > 0 && dy > 0)
            {
                if (dx < dy && ans[cni] == inf)
                {
                    ans[cni] = dy;
                }
                else if (dy < dx && ans[cni] == inf)
                {
                    ans[cei] = dx;
                    break;
                }
            }
        }
    }

    for (int &x : ans)
    {
        if (x == inf)
            cout << "Infinity" << "\n";
        else
            cout << x << "\n";
    }
}

signed main()
{
    cin >> n;
    d = vector<char>(n);
    cow = vector<pi>(n);
    for (int i = 0; i < n; i++)
        cin >> d[i] >> cow[i].first >> cow[i].second;
    solve();
    return 0;
}