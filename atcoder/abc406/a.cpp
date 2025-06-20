
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (c < a)
    {
        cout << "Yes\n";
    }
    else if (c == a)
    {
        if (d <= b)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}