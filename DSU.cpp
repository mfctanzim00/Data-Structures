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

     void combine(int u, int v){
           int uPar = root(u);
           int vPar = root(v);

           if(uPar==vPar)return;
           if(sz[uPar]<sz[vPar])
               swap(uPar, vPar);

           sz[uPar]+=sz[vPar];
           par[vPar]=uPar;
     }
};
