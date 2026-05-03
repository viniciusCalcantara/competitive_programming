#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

vector<int> z_function_trivial(string s) {
    int n = s.size();
    vector<int> z(n, 0);
    for (int i = 1; i < n; i++) {
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
    }
    return z;
}

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main() {
  string s[] = {"aaaaa",
                "aaaabaa",
                "abacaba"};

  for (int i = 0; i < 3; i++) {
    auto v = z_function(s[i]);
    for (auto x : v)
      cout << x << " ";
    cout << endl;
  }

  return 0;
}
