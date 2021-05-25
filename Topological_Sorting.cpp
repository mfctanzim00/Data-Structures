
/* Problem Link (Course Schedule) : https://cses.fi/problemset/result/1074592/ */

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
vector<int>graph[mx], ret;
bool cycle_found = false, vis[mx], visit[mx];
int last_node = -1, in_deg[mx];
stack<int>s;

void topological_sort(int src)
{
    visit[src] = true;
    for(auto x: graph[src]){
              if(!visit[x]){
                       topological_sort(x);
              }
    }
    s.push(src);
}

void Dfs(int src)
{
    vis[src] = true;
    for(auto x: graph[src]){
              if(!vis[x]){
                       Dfs(x);
              }
              else{
                       last_node = x;
                       return;
              }
              if(cycle_found){
                       return;
              }
              if(~last_node){
                       if(src==last_node){
                                 cycle_found = true;
                       }
                       return;
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
             in_deg[b]++;
    }
    for(int i=1; i<=n; i++){
             if(!visit[i]){
                      topological_sort(i);
             }
    }
    while(!s.empty()&&!cycle_found){
             int x = s.top();
             s.pop();
             if(!vis[x]){
                      Dfs(x);
             }
    }
    if(cycle_found){
             cout << "IMPOSSIBLE" << '\n';
    }
    else{
            queue<int>q;
            for(int i=1; i<=n; i++){
                      if(!in_deg[i]){
                               q.push(i);
                      }
            }
            vector<int>ret;
            while(!q.empty()){
                      int x = q.front();
                      q.pop();
                      ret.pb(x);
                      for(auto xx: graph[x]){
                                 in_deg[xx]--;
                                 if(!in_deg[xx]){
                                            q.push(xx);
                                 }
                      }
            }
            for(auto x: ret){
                      cout << x << " ";
            }
            cout << "\n";
    }

    return 0;
}
