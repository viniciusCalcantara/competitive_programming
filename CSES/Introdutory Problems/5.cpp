#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;

    if (n == 2 || n == 3)
    {
        cout << "NO SOLUTION\n";
    }
    else
    {
        int a, b;
        if (n & 1)
        {
            a = n; 
            b = n - 1;
        }
        else 
        {
            b = n;
            a = n - 1;
        }
        for (int x = a; x > 0; x -= 2)
            cout << x << " ";
        for (int x = b; x > 0; x -= 2)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}