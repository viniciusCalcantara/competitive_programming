#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long int
#define endl '\n'
#define pb push_back
#define pi pair<int, int>
#define pii pair<int, pi>
#define fir first
#define sec second
#define MAXN 200005
#define mod 998244353
#define INF 1e9

struct lazy_segtree {

  int n;
  vector<int> seg, lazy;

  lazy_segtree(int size) {
    n = size;
    seg.assign(2 * n - 1, 0);
    lazy.assign(2 * n - 1, 0);
    // for build
    // build(arr, 0, 0, n - 1);
  }

  int left(int v) {
    return v + 1;
  }

  int right(int v, int l, int mid) {
    return v + 2 * (mid - l + 1);
  }
 
  void build(vector<int>& arr, int v, int l, int r) {
    if (l == r) {
      seg[v] = arr[l];
    } else {
      int mid = (l + r) / 2;
      build(arr, left(v), l, mid);
      build(arr, right(v, l, mid), mid+1, r);
      seg[v] = min(seg[left(v)], seg[right(v, l, mid)]);
    }
  }

  void push(int v, int l, int mid) {
    int left_child = left(v);
    int right_child = right(v, l, mid);
    seg[left_child] += lazy[v];
    lazy[left_child] += lazy[v];
    seg[right_child] += lazy[v];
    lazy[right_child] += lazy[v];
    lazy[v] = 0;
  }

  void update(int v, int l, int r, int ql, int qr, int addend) {
    if (ql > qr) 
      return;
    
    if (ql == l && qr == r) {
      seg[v] += addend;
      lazy[v] += addend;
    } else {
      int mid = (l + r) / 2;
      push(v, l, mid);
      update(left(v), l, mid, ql, min(qr, mid), addend);
      update(right(v, l, mid), mid+1, r, max(ql, mid+1), qr, addend);
      seg[v] = min(seg[left(v)], seg[right(v, l, mid)]);
    }
  }

  int query(int v, int l, int r, int ql, int qr) {
    if (ql > qr)
      return INF;
    
    if (l == ql && qr == r)
      return seg[v];
    
    int mid = (l + r) / 2;
    push(v, l, mid);
    return min(query(left(v), l, mid, ql, min(qr, mid)), 
               query(right(v, l, mid), mid+1, r, max(ql, mid+1), qr));
  }

  void upd(int ql, int qr, int addend) {
    update(0, 0, n - 1, ql, qr, addend);
  }

  int qry(int ql, int qr) {
    return query(0, 0, n - 1, ql, qr);
  }
};
