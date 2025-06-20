#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s; cin >> n >> s;

    vector<int> v(n);
    for (auto &x : v) cin >> x;

    int d = 0;
    int sleep = false;
    for (int &x : v)
    {
        if (x - d > s)
        {
            sleep = true;
            break;
        }
        d = x;
    }

    sleep ? cout << "No\n" : cout << "Yes\n";
    return 0;
}