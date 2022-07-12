// gp_hash_table: https://codeforces.com/blog/entry/60737?fbclid=IwAR0qVSvW6k_IbSftzUvQvVUukgf09Fq6q70W5gWzhYuW0a6UpWtr7h18ZNs
// https://gist.github.com/Chillee/3bd6ee4429abb4a2e7c19959fb1490ae





//================ gp hash table ======================
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
struct chash {
    const long long RANDOM = (long long)(make_unique<char>().get()) ^ chrono::high_resolution_clock::now().time_since_epoch().count();
    static unsigned long long hash_f(unsigned long long x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    static unsigned hash_combine(unsigned a, unsigned b) { return a * 31 + b; }
    long long operator()(long long x) const { return hash_f(x)^RANDOM; }
};
gp_hash_table<long long, long long, chash> ans, frq, last;
//=====================================================
