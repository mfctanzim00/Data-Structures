#include<bits/stdc++.h>
using namespace std;
#define bug(a) cerr<<#a<<" : "<<a<<endl

struct data{
    int u, v, w;
    data(){}
    data(int _u, int _v, int _w){
          u = _u;
          v = _v;
          w = _w;
    }
};

struct DSU{
     int N;
     vector<int>par, sz;

     void init(int n){
           N = n;
           for(int i=0; i<=n; i++){
               par.push_back(i);
               sz.push_back(1);
           }
     }
     int root(int r){
           if(par[r]==r)
               return r;
           return par[r]=root(par[r]);
     }

     bool combine(int u, int v){
           int uPar = root(u);
           int vPar = root(v);

           if(uPar==vPar)return false;

           if(sz[uPar]<sz[vPar])
               swap(uPar, vPar);

           sz[uPar]+=sz[vPar];
           par[vPar]=uPar;

           return true;
     }
};

long long solve(vector<data>graph, int n)
{
    DSU dsu;
    dsu.init(n);

    long long ans=0;
    for(int i=0; i<graph.size(); i++){
           int u = graph[i].u, v = graph[i].v;
           if(dsu.combine(u, v)){
                 ans+=graph[i].w;
           }
    }
    return ans;
}

int main()
{
    int t=1, n, m, k;
    cin >> t;

    int cs=0;
    while(t--){
            vector<data>graph;
            scanf("%d", &n);
            while(true){
                   int u, v, w;
                   scanf("%d %d %d", &u, &v, &w);
                   if(u==0 && v==0 && w==0)break;
                   graph.push_back(data(u, v, w));
            }
            sort(graph.begin(), graph.end(), [&](const data &a, const data &b){
                   return a.w > b.w;
            });
            long long p = solve(graph, n);

            reverse(graph.begin(), graph.end());
            long long q = solve(graph, n);

            printf("Case %d: ", ++cs);
            if((p+q)%2==0)
                  printf("%lld\n", (p+q)/2);
            else printf("%lld/2\n", (p+q));
    }
    return 0;
}
