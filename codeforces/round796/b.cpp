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

        int closest_odd = 0, shift_count = 50;
        int even_count = 0;
        int ans = 0;
        for (int &x : v)
        {
            cin >> x;
            int aux = 0;
            if (!(x & 1))
            {
                even_count++;
                aux = __builtin_ffs(x) - 1;
                if (aux < shift_count)
                {
                    closest_odd = x;
                    shift_count = aux;
                }
            }
        }


        if (even_count == n)
        {
            cout << shift_count + (even_count - 1) << "\n";
        }
        else if (even_count < n)
        {
            cout << even_count << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }
    return 0;
}
