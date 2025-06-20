#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    vector<int> a(3);
    int c;

    for (int i = 0; i < 3; i++)
    {
        cin >> c;
        if (c == 0) continue;
        a[--c]++;
    }

    for (int i = 0; i < 3; i++)
    {
        if (a[i] == 0)
            cout << i + 1 << "\n";
    }

    return 0;
}