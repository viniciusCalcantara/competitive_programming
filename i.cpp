#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<vector<int>> v(26);
    for (int i = 0; i < n; i++)
    {
        int freq = 0;
        string s; cin >> s;
        vector<int> aux(26);
        for (char c : s)
        {
            freq++;
            aux[c - 'a'] = freq;
        }
        

    }
    for (int i = 0 ; i < 26; i++)
        cout << v[i] << " ";
    cout << "\n"; 
    return 0;
}
