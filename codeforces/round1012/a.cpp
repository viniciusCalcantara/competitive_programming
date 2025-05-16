#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int x, y, a; cin >> x >> y >> a;
        int mod = a % (x + y);

        int turn = -1;
        do
        {
            turn++;
            turn %= 2;
            if (turn == 0)
                mod -= x;
            else
                mod -= y;
        } while (mod >= 0);
        
        if (turn == 0)
            cout << "NO\n";
        else if (turn == 1)
            cout << "YES\n";
    }

}