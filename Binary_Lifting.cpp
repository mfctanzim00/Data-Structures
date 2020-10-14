/*
      Problem Link: https://cses.fi/problemset/task/1687/
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
const ll mx = 1e6+7;

ll posx[] = {1,-1, 0, 0};
ll posy[] = {0, 0, 1,-1};
vector<int>vec[200009];
ll tree[200009][20], n;

void Dfs(ll src, ll par)
{
    tree[src][0] = par;
    for(int i=1; i<log2(n); i++){
             if(~tree[src][i-1])
                      tree[src][i] = tree[tree[src][i-1]][i-1];
             else
                      tree[src][i] = -1;
    }
    for(auto x: vec[src])
             if(x!=par)
                       Dfs(x, src);
}

///Binary_Lifting
ll query(ll src, ll k)
{
    if(src==-1 || k==0)
             return src;

    for(ll i=log2(n); i>=0; i--)
             if(k>=(1<<i))
                      return query(tree[src][i], k-(1<<i));
}

int main()
{
    //FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif /// Mfc_Tanzim

    ll t=1, k, m, a, b, c, d;
    //cin >> t;

    while(t--){
              cin >> n >> k;
              for(ll i=2; i<=n; i++){
                       cin >> a;
                       vec[a].pb(i);
                       vec[i].pb(a);
              }
              Dfs(1, -1);
              while(k--){
                        cin >> a >> b;
                        if(a==b){
                                 cout << -1 << endl;
                                 continue;
                        }
                        cout << query(a, b) << endl;
              }
    }

    return 0;
}
