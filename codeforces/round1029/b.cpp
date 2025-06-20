#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n; cin >> n;
        cout << 1 << " ";
        for (int i = 3; i <= n; i++)
            cout << i << " ";
        cout << 2 << "\n";
    }
    return 0;
}