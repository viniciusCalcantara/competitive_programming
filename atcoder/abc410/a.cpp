#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, nn;
    cin >> n;
    vector<int> v(n);
    for (int &x : v) cin >> x;
    cin >> nn;

    int cont = 0;
    for (int &x : v)
        if (x >= nn)
            cont++;

    cout << cont << "\n";
    return 0;
}