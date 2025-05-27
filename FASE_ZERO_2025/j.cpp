#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, k;
vector<ll> v;

int main()
{
    cin >> n >> k;
    v = vector<ll>(2 * n);

    // a[i] + (j - i) * k > a[j]
    // a[i] - k * i > a[j] - k * j
    int ai;
    for (int i = 0; i < n; i++)
    {
        cin >> ai;
        v[i] =  ai - 1LL * k * i;
        v[i + n] = ai - 1LL * k * (i + n);
    }

    vector<int> ans(2 * n);
    stack<int> s;
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!s.empty() && v[s.top()] >= v[i])
            s.pop();

        if (!s.empty())
            s.top() >= n ? ans[i] = s.top() - n : ans[i] = s.top();
            
        s.push(i);
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] + 1 << " ";
    cout << "\n";
    return 0;
}