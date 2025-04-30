#include <bits/stdc++.h>
#define fir first
#define sec second
#define pi pair<int, int>

using namespace std;
using ll = long long;

// Custom hash using splitmix64 to guard against collision attacks
struct custom_hash {
    // splitmix64 mixer by Sebastiano Vigna
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }

    size_t operator()(const pair<int, int>& x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        uint64_t key = (uint64_t(x.first) << 32) | uint32_t(x.second);
        return splitmix64(key + FIXED_RANDOM);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<pi, int, custom_hash> mp;
    mp.reserve(1 << 17);
    mp.max_load_factor(0.25);
    return 0;
}
