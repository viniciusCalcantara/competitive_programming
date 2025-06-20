#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> trial_division(int n)
{
    vector<int> factorization;
    for (long long d = 2; d * d <= n; d++)
    {
        while (n % d == 0)
        {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int y, k;
    cin >> y >> k;

    vector<int> primes = trial_division(y);
    
    int i = 0;
    ll x = 1, min_d = 1, t;
    for (int p : primes)
    {
        min_d *= primes[i];
        t = primes[i++] - 1;
        if (t > k) break;
        k -= t;
        x = min_d;
    }
    cout << x + 1LL * k * x << "\n";
    return 0;
}