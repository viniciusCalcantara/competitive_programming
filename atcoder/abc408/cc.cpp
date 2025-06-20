#include <bits/stdc++.h>

#define MAXN 1'000'000
#define INF 300'000
using namespace std;
using ll = long long;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    
    int l, r;
    vector<int> v(n + 1);
    while (m--)
    {
        cin >> l >> r;
        l--;
        r--;
        v[l] += 1;
        v[r + 1] -= 1;
    }

    for(int i = 0; i + 1 < n; i++)
        v[i + 1] += v[i];
    
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
        ans = min(ans, v[i]);
    
    cout << ans << "\n";
    return 0;
}