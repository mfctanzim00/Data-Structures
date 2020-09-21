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
const ll mx = 1e9+7;

ll posx[] = {1,-1, 0, 0};
ll posy[] = {0, 0, 1,-1}, n;
vector<int>tree[200009];
int level[200009], dp[200009][99], parent[200009];

void dfs(int src,int par,int lev)
{
    level[src] = lev;
    parent[src] = par;
    for(auto x: tree[src]){
                if(x!=par)
                        dfs(x,src,lev+1);
    }
}
int Lca(int u,int v)
{
    if(level[u] < level[v])
        swap(u,v);

    for(int i=log2(n); i>=0; i--){
              if(level[u]-(1<<i) >= level[v])
                         u = dp[u][i];
    }
    if(u == v)
        return u;

    for(int i=log2(n); i>=0; i--){
              if(dp[u][i] != dp[v][i]){
                         u = dp[u][i];
                         v = dp[v][i];
              }
    }
    return parent[u];
}

int main()
{
    FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif /// Mfc_Tanzim

    int t=1, k, m, a, b, c, d;
    //cin >> t;

    while(t--){
              cin >> n >> k;
              for(ll i=1; i<n; i++){
                       cin >> a >> b;
                       tree[a].pb(b);
                       tree[b].pb(a);
              }

              dfs(1,1,0);
              memset(dp,-1,sizeof(dp));
              for(int i=1; i<=n; i++)
                      dp[i][0] = parent[i];
              for(int j=1; (1<<j)<n; j++){
                      for(int i=1; i<=n; i++){
                               if(~dp[i][j-1])
                                        dp[i][j] = dp[dp[i][j-1]][j-1];
                      }
              }
              while(k--){
                        cin >> a >> b;
                        cout << Lca(a, b) << endl;
              }
    }
    return 0;
}
