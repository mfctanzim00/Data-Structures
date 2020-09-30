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
const ll mod = 1e9+7;
const ll mx = 2e5+10;

ll posx[] = {1,-1, 0, 0};
ll posy[] = {0, 0, 1,-1};
vector<int>graph[mx], path;
int vis[mx], parent[mx], source, dest;
bool found = false;

void Dfs(int src, int par)
{
    vis[src] = true;
    for(auto x: graph[src]){
             if(x!=par){
                      if(!vis[x]){
                               parent[x] = src;
                               Dfs(x, src);
                      }
                      else{
                               source = x, dest = src;
                               found = true;
                      }
             }
    }
}

int main()
{
     FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif /// Mfc_Tanzim

    int n, e;
    cin >> n >> e;
    while(e--){
             int a, b;
             cin >> a >> b;
             graph[a].pb(b);
             graph[b].pb(a);
    }
    for(int i=1; i<=n&&!found; i++){
             if(!vis[i]){
                      Dfs(i, 0);
             }
    }
    if(!found){
             cout << "IMPOSSIBLE" << '\n';
    }
    else{
             while(source!=dest){
                        path.pb(source);
                        source = parent[source];
             }
             path.pb(source);
             reverse all(path);
             path.pb(source);
             cout << path.size() << endl;
             for(auto x: path){
                        cout << x << " ";
             }
             cout << "\n";
    }

    return 0;
}

