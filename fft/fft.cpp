#include <bits/stdc++.h>

using namespace std;

#define PI acos(-1)
#define int long long int
#define pb push_back
#define pi pair<int, int>
#define pii pair<pi, int>
#define fir first
#define sec second
#define MAXN 125001
#define mod 1000000007
#define cd complex<double>

namespace fft
{
  int n;

  void fft(vector<cd> &a, bool invert)
  {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++)
    {
      int bit = n >> 1;
      for (; j & bit; bit >>= 1)
        j ^= bit;
      j ^= bit;
      if (i < j)
        swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1)
    {
      double ang = 2 * PI / len * (invert ? -1 : 1);
      cd wlen(cos(ang), sin(ang));
      for (int i = 0; i < n; i += len)
      {
        cd w(1);
        for (int j = 0; j < len / 2; j++)
        {
          cd u = a[i + j], v = a[i + j + len / 2] * w;
          a[i + j] = u + v;
          a[i + j + len / 2] = u - v;
          w *= wlen;
        }
      }
    }
    if (invert)
      for (cd &x : a)
        x /= n;
  }
  
  vector<int> mul(vector<int> a, vector<int> b)
  {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    n = 1;
    while (n < a.size() + b.size())
      n <<= 1;
    fa.resize(n);
    fb.resize(n);
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
      fa[i] *= fb[i];
    fft(fa, true);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
      ans[i] = round(fa[i].real());
    return ans;
  }
}

signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);

  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 0; i < m; i++)
    cin >> b[i];

  vector<int> res = fft::mul(a, b);

  for (int i = 0; i < n + m - 1; i++)
    cout << res[i] << " ";

  cout << "\n";
  return 0;
}
