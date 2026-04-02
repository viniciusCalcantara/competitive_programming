#include <bits/stdc++.h>

using namespace std;

// String hashing from:
// https://cp-algorithms.com/string/string-hashing.html

// considering only a lowercase english letters alphabet
// conversion used: a->1, b->2, ..., z->26.
// precomputing the powers of p might give a performance boost
long long compute_hash(string const& s) {
  const int p = 31;
  const int m = 1e9 + 9;
  long long hash_value = 0;
  long long p_pow = 1;
  for (char c : s) {
    hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
    p_pow = (p_pow * p) % m;
  }
  return hash_value;
}

vector<string> s = {
    "apple",
    "banana",
    "orange",
    "apple",
    "grape",
    "banana",
    "kiwi"
};

vector<vector<int>> group_identical_strings(vector<string> const& s) {
  int n = s.size();

  vector<pair<long long, int>> hashes(n);
  for (int i = 0; i < n; i++)
    hashes[i] = {compute_hash(s[i]), i};

  sort(hashes.begin(), hashes.end());

  vector<vector<int>> groups;
  for (int i = 0; i < n; i++) {
    if (i == 0 || hashes[i].first != hashes[i - 1].first)
      groups.emplace_back();
    groups.back().push_back(hashes[i].second);
  }

  return groups;
}

vector<vector<int>> group_identical_strings_without_hash(vector<string>& s) {
  int n = s.size();

  sort(s.begin(), s.end());

  for (auto ss : s)
    cout << ss << " ";
  cout << "\n";

  vector<vector<int>> groups;
  for (int i = 0; i < n; i++) {
    if (i == 0 || s[i] != s[i - 1])
      groups.emplace_back();
    groups.back().push_back(i);
  }

  return groups;
}

int main() {
  vector<vector<int>> groups = group_identical_strings_without_hash(s);
  for (auto g : groups) {
    cout << "-------------\n";
    for (auto i : g) {
      cout << s[i] << "\n";
    }
  }
  return 0;
}
