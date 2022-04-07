/*
      Problem Link:  https://codeforces.com/contest/1354/problem/D
*/

#include<bits/stdc++.h>
#define bug(a) cerr<<#a<<" : "<<a<<endl
using namespace std;

struct BIT{
      int N;
      vector<int>tree;

      void init(int n){
            N = n;
            tree.assign(n+1, 0);
      }
      void update(int idx, int value){
            while(idx<=N){
                  tree[idx] += value;
                  idx += (idx&(-idx));
            }
      }
      int query(int idx){
            int sum = 0;
            while(idx){
                  sum += tree[idx];
                  idx -= (idx&(-idx));
            }
            return sum;
      }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t=1, n, m, k;
    //cin >> t;

    while(t--){
            int q;
            cin >> n >> q;

            BIT bit;
            bit.init(n+1);

            for(int i=1; i<=n; i++){
                     cin >> k;
                     bit.update(k, +1);
            }
            while(q--){
                     cin >> k;
                     if(k>=1){
                           bit.update(k, +1);
                     }
                     else {
                           k=-k;
                           int ans=-1;
                           int l=1, r=n;
                           while(l<=r){
                                 int mid=(l+r)>>1;
                                 if(bit.query(mid)>=k){
                                       ans=mid;
                                       r=mid-1;
                                 }
                                 else l=mid+1;
                           }
                          // cout << ans << endl;
                           if(~ans)
                                 bit.update(ans, -1);
                     }
            }
            int res=0;
            for(int i=1; i<=n; i++){
                     if((bit.query(i)-bit.query(i-1))==0)continue;
                     res=i;
                     break;
            }
            cout << res << endl;
    }
    return 0;
}
