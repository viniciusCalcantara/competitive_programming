#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define endl '\n'
#define pb push_back
#define pi pair<int, int>
#define pii pair<int, pi>
#define fir first
#define sec second
#define MAXN 250005
#define mod 998244353
 
typedef long long ll;
 
template<int p> struct mod_int {
	ll expo(ll b, ll e) {
		ll ret = 1;
		while (e) {
			if (e % 2) ret = ret * b % p;
			e /= 2, b = b * b % p;
		}
		return ret;
	}
	ll inv(ll b) { return expo(b, p-2); }
 
	using m = mod_int;
	int v;
	mod_int() : v(0) {}
	mod_int(ll v_) {
		if (v_ >= p or v_ <= -p) v_ %= p;
		if (v_ < 0) v_ += p;
		v = v_;
	}
	m& operator +=(const m& a) {
		v += a.v;
		if (v >= p) v -= p;
		return *this;
	}
	m& operator -=(const m& a) {
		v -= a.v;
		if (v < 0) v += p;
		return *this;
	}
	m& operator *=(const m& a) {
		v = v * ll(a.v) % p;
		return *this;
	}
	m& operator /=(const m& a) {
		v = v * inv(a.v) % p;
		return *this;
	}
	m operator -(){ return m(-v); }
	m& operator ^=(ll e) {
		if (e < 0) {
			v = inv(v);
			e = -e;
		}
		v = expo(v, e);
		// possivel otimizacao:
		// cuidado com 0^0
		// v = expo(v, e%(p-1)); 
		return *this;
	}
	bool operator ==(const m& a) { return v == a.v; }
	bool operator !=(const m& a) { return v != a.v; }
 
	friend istream& operator >>(istream& in, m& a) {
		ll val; in >> val;
		a = m(val);
		return in;
	}
	friend ostream& operator <<(ostream& out, m a) {
		return out << a.v;
	}
	friend m operator +(m a, m b) { return a += b; }
	friend m operator -(m a, m b) { return a -= b; }
	friend m operator *(m a, m b) { return a *= b; }
	friend m operator /(m a, m b) { return a /= b; }
	friend m operator ^(m a, ll e) { return a ^= e; }
};
 
typedef mod_int<mod> mint;
 
 
void fix(vector<mint> & a)
{
  while (a.size() > 0 && a.back() == 0)
    a.pop_back();
}
 
namespace fft {
  
  // NTT
  //
  // Precisa do mint (primitivas de aritmetica modular)
  //
  // O(n log (n))
 
  const int MOD = 998244353;
  typedef mod_int<MOD> mint;
 
  void ntt(vector<mint>& a, bool rev) {
	int n = a.size(); auto b = a;
	assert(!(n&(n-1)));
	mint g = 1; 
	while ((g^(MOD / 2)) == 1) g += 1;
	if (rev) g = 1 / g;
 
	for (int step = n / 2; step; step /= 2) {
      mint w = g^(MOD / (n / step)), wn = 1;
      for (int i = 0; i < n/2; i += step) {
        for (int j = 0; j < step; j++) {
          auto u = a[2 * i + j], v = wn * a[2 * i + j + step];
          b[i+j] = u + v; b[i + n/2 + j] = u - v;
        }
        wn = wn * w;
      }
      swap(a, b);
	}
	if (rev) {
      auto n1 = mint(1) / n;
      for (auto& x : a) x *= n1;
	}
  }
 
  vector<mint> mul(const vector<mint>& a, const vector<mint>& b) {
	vector<mint> l(a.begin(), a.end()), r(b.begin(), b.end());
	int N = l.size()+r.size()-1, n = 1 << __lg(2*N - 1);
	l.resize(n);
	r.resize(n);
	ntt(l, false);
	ntt(r, false);
	for (int i = 0; i < n; i++) l[i] *= r[i];
	ntt(l, true);
	l.resize(N);
	return l;
  }
 
}
 
int np, nq;
vector<mint> p, q;
const int MAXLOG = 9; // o máximo que aparece é q(x)^(256), 256 = 2^9;
vector<mint> pot_q[MAXLOG]; // pot_q[i] = q(x)^(2^i);
 
vector<mint> merge(vector<mint> & a, vector<mint> & b) {
  int size = max(a.size(), b.size());
  vector<mint> merge(size, 0);
  for (int i = 0; i < size; i++) {
    if (i < a.size())
      merge[i] = (merge[i] + a[i]);
    if (i < b.size())
      merge[i] = (merge[i] + b[i]);
   }
  
  return merge;
}
 
vector<mint> func(int ini, int fim) {
  int len = fim - ini + 1;
  if (len == 1) {
     vector<mint> ret;
    ret.push_back(p[ini]);
    return ret;
  }
 
  int power = 0;
  while ((1 << (power + 1)) < len)
    power++;
 
  vector<mint> a = func(ini, ini + (1 << power) - 1);
  vector<mint> b = func(ini + (1 << power), fim);
  b = fft::mul(b, pot_q[power]);
  return merge(a, b);
  
}
 
signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  cin >> np;
  np++;
  p.resize(np);
  for (int i = 0 ; i < np; i++) {
    cin >> p[i];
  }
 
  cin >> nq;
  nq++;
  q.resize(nq);
  for (int i = 0; i < nq; i++) {
    cin >> q[i];
  }
 
  pot_q[0] = q;
  for (int i = 1; (1 << i) <= np; i++) {
    pot_q[i] = fft::mul(pot_q[i - 1], pot_q[i - 1]);
  }
 
  nq--;
  np--;
  vector<mint> ans = func(0, np);
  for (int i = 0; i < nq * np + 1; i++)
    cout << ans[i] << " ";
  return 0;
}
