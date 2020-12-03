/*
     Problem Link: https://codeforces.com/contest/1042/problem/D
*/

#include<bits/stdc++.h>
#include<cstring>
//#define Mfc_Tanzim
#define   ll         long long
#define   ull        unsigned long long
#define   pb         push_back
#define   ff         first
#define   ss         second
#define   all(v)     (v.begin(), v.end())
#define   rall(v)    (v.rbegin(), v.rend())
#define   pi         acos(-1.0)
#define   FastRead   ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define   bug(a)     cerr << #a << " : " << a << endl
using namespace std;
const int mx = 2e6+9;

ll posx[] = {1,-1, 0, 0};
ll posy[] = {0, 0, 1,-1};
ll cumu[mx];
vector<ll>tree[3*mx];

void build(int node, int start, int end)
{
    if(start==end){
            tree[node].push_back(cumu[start]);
            return;
    }
    int mid = (start+end)>>1;
    build(node<<1, start, mid);
    build(node<<1|1, mid+1, end);

    merge(tree[node<<1].begin(), tree[node<<1].end(), tree[node<<1|1].begin(), tree[node<<1|1].end(), back_inserter(tree[node]));
}

ll query(int node, int start, int end, int i, int j, ll val)
{
    if(i>end || j<start)
            return 0;
    if(start>=i && end<=j)
            return lower_bound(tree[node].begin(), tree[node].end(), val)-tree[node].begin();

    int mid = (start+end)>>1;
    int x = query(node<<1, start, mid, i, j, val);
    int y = query(node<<1|1, mid+1, end, i, j, val);

    return (x+y);
}

int main()
{
    FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif /// Mfc_Tanzim

    ll t=1, n, l, r, a, val;
    //cin >> t;

    while(t--){
             cin >> n >> val;
             for(int i=1; i<=n; i++){
                       cin >> a;
                       cumu[i] = cumu[i-1]+a;
             }
             build(1, 1, n);

             ll ret = 0;
             for(int i=1; i<=n; i++){
                       ret+=query(1, 1, n, i, n, val+cumu[i-1]);
             }
             cout << ret << endl;
    }
    return 0;
}

