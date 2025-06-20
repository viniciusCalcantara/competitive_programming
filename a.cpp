#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y; cin >> x >> y;
    int a = (x + y) / 2;
    int b = x - a;
    cout << a << " " <<  b << "\n";
    return 0;
}