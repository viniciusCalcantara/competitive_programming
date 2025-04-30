#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    string s; cin >> s;
    vector<int> f(26);
    int cont = 0, current = 0;
    for (int it = 0; it < (int)s.size(); it++)
    {
        while (it < (int)s.size() && s[current] == s[it]) cont++, it++;
        if (cont > f[s[current] - 'A']) f[s[current] - 'A'] = cont;
        current = it;
        cont = 1;
    }

    int max = 0;
    for (int i = 0; i < 26; i++)
        if (f[i] > max)
            max = f[i];

    cout << max << "\n";
    return 0;
}