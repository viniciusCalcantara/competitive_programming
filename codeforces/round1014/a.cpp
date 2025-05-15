#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int min = 1e9, max = 1;
        int aux;
        while (n--)
        {
            cin >> aux;
            if (aux < min) min = aux;
            if (aux > max) max = aux;
        }
        cout << max - min << "\n";
    }
    return 0;
}
// https://codeforces.com/contest/2092/problem/A
// gcd(ai + d, aj + d) = gcd(aj - ai, aj + d)
// it's sufficient to choose d such that (aj - ai) | (aj + d)

// gcd(x, y) = |x - y| because x = ai + d, and y = aj + d;