#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> box(n);

    int b;
    vector<int> ans;
    for (int i = 0; i < m; i++)
    {
        cin >> b;
        if (b)
        {
            b--;
            box[b]++;
            ans.push_back(b);
        }
        else
        {
            int less = 101;
            for (int j = 0; j < n; j++)
            {
                if (less > box[j])
                    less = box[j];
            }

            int first = -1;
            for (int j = 0; j < n; j++)
            {
                if (box[j] == less)
                {
                    first = j;
                    break;
                }
            }
            box[first]++;
            ans.push_back(first);
        }
    }
    for (int &x : ans) cout << x + 1 << " ";
    cout << "\n";

    return 0;
}