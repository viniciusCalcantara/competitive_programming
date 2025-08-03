/*

Input:
    Uma sequencia com n interiros.

Output:
    1. qual o tamanho da maior subsequência crescente?
    2. gere uma sequência de maior tamanho tamanho.

Concepts:
    subsequencia -> subconjunto ordenado de elementos da entrada
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> input = {8, 3, 4, 6, 5, 2, 0, 7, 9, 1};

int lis(vector<int> const &a)
{
    int n = a.size();
    const int inf = 1e9;
    vector<int> d(n + 1, inf), pos(n, -1), p(n + 1, -1);
    d[0] = -inf;

    int length = 0, last = -1;
    for (int i = 0; i < n; i++)
    {
        int l = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[l - 1] < a[i] && a[i] < d[l])
        {
            d[l] = a[i];
            pos[l] = i;
            p[i] = pos[l - 1];
        }

        if (l > length)
        {
            length = l;
            last = i;
        }
    }

    vector<int> subseq;
    while (last != -1)
    {
        subseq.push_back(a[last]);
        last = p[last];
    }
    reverse(subseq.begin(), subseq.end());
    
    for (auto x : subseq) {
        cout << x << " ";
    }
    cout << "\n";

    return subseq.size();
}

int main()
{
    cout << lis(input) << "\n"; 
    return 0;
}