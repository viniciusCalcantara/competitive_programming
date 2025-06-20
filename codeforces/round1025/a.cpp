#include <bits/stdc++.h>
#define fir first
#define sec second
#define pi pair<int, int>
#define MAXN 4'000'010
#define mod 998'244'353

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
        int n;
        cin >> n;
        vector<int> v(n);
        for (int &x : v)
            cin >> x;

        int flag1 = 0;
        for (int i = 0; i < n; i++)
            if (!v[i])
                flag1 = 1;

        int flag2 = 0;
        for (int i = 0; i + 1 < n; i++)
            if (!v[i] && !v[i + 1])
                flag2 = true;
        
        if (flag1 && !flag2)
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
        }
    }
    return 0;
}
