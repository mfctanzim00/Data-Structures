/*
     Problem Link : http://lightoj.com/volume_showproblem.php?problem=1112
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
const int mx = 2e5+9;

ll posx[] = {1,-1, 0, 0};
ll posy[] = {0, 0, 1,-1};
int tree[100006], arr[100006];

void BIT_update(int idx, int value, int n)
{
    while(idx<=n){
             tree[idx]+=value;
             idx+=(idx&(-idx));
    }
}

ll query(int idx)
{
    ll sum = 0;
    while(idx){
             sum+=tree[idx];
             idx-=(idx&(-idx));
    }
    return sum;
}

int main()
{
    //FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif /// Mfc_Tanzim

    int t=1, n, k, m, q, cs = 1, pos, l, r, type, val;
    scanf("%d", &t);

    while(t--){
             memset(tree, 0, sizeof(tree));
             scanf("%d %d", &n, &q);
             for(int i=1; i<=n; i++){
                        cin >> arr[i];
                        BIT_update(i, arr[i], n);
             }

             printf("Case %d:\n", cs++);
             while(q--){
                        scanf("%d", &type);
                        if(type==1){
                                  scanf("%d", &pos);
                                  pos++;
                                  printf("%d\n", arr[pos]);
                                  BIT_update(pos, -arr[pos], n);
                                  arr[pos] = 0;
                        }
                        else if(type==2){
                                  scanf("%d %d", &pos, &val);
                                  pos++;
                                  arr[pos]+=val;
                                  BIT_update(pos, val, n);
                        }
                        else{
                                  scanf("%d %d", &l, &r);
                                  l++, r++;
                                  printf("%d\n", query(r)-query(l-1));
                        }
             }
    }
    return 0;
}
