#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> v(101);
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v[x]++;
    }

    int cont = 0;
    for (int i = 1; i <= 100; i++)
    {
        if (v[i] >= 1)
        {  
            cont++;
        }
    }

    cout << cont << "\n";
        for (int i = 1; i <= 100; i++)
    {
        if (v[i] >= 1)
        {  
            cout << i << " ";
        }
    }
    cout << "\n";
    return 0;
}