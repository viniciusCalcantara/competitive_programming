#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ll n; cin >> n;

    while (n != 1)
    {
        cout << n << " ";
        (n & 1) == 0 ? n >>= 1 : n = n * 3 + 1;   
    }
    cout << 1 << "\n"; 
    return 0;
}