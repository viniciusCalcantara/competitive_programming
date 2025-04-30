#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n, aux; cin >> n;
    vector<int> f(n);
   
    int x;
    aux = n;
    while (aux > 1)
    {
        cin >> x;
        f[--x]++;
        aux--;
    }

    for (int i = 0; i < n; i++)
    {
        if (f[i] == 0)
        {
            cout << i + 1 << "\n";
            break;
        }
    }
    return 0;
}