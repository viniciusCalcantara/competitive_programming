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
        int n, x;
        cin >> n >> x;
        vector<int> v(n), ones;
        for (int &x : v)
            cin >> x;
        
        int fir = -1, sec = n;
        for (int i = 0; i < n; i++)
            if (v[i])
                fir = i;
        
        for (int i = n - 1; i >= 0; i--)
            if (v[i])
                sec = i;
        if ((fir - sec + 1) <= x)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}