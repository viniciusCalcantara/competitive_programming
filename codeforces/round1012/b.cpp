#include <bits/stdc++.h>

#define vvi vector<vector<int>>
#define vi vector<int>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        vector<int> l(n, -1);
        vector<int> c(m, -1);
        for (string &s : grid)
            cin >> s;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '0')
                {
                    if (l[i] == -1) l[i] = j;
                    if (c[j] == -1) c[j] = i;
                }
            }
        }

        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    if (l[i] != -1 && l[i] < j && c[j] != -1 && c[j] < i)
                        flag = true;
                }
            }
        }
        if (!flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}