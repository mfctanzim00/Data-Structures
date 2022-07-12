// gp_hash_table: https://codeforces.com/blog/entry/60737?fbclid=IwAR0qVSvW6k_IbSftzUvQvVUukgf09Fq6q70W5gWzhYuW0a6UpWtr7h18ZNs

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const long long RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(long long x) const { return x ^ RANDOM; }
};
gp_hash_table<long long, long long, chash> table;
