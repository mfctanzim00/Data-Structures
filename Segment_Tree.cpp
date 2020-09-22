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
ll tree[3*mx], arr[mx];

void build(ll node, ll start, ll end)
{
    if(start==end){
            tree[node] = arr[start];
            return;
    }

    ll left = 2*node;
    ll right = 2*node+1;
    ll mid = (start+end)>>1;

    build(left, start, mid);
    build(right, mid+1, end);

    tree[node] = tree[left]+tree[right];
}

void update(ll node, ll start, ll end, ll i, ll newvalue)
{
    if(i<start || i>end)
             return;
    if(start>=i && end<=i){
             tree[node] = newvalue;
             return;
    }
    ll left = 2*node;
    ll right = 2*node+1;
    ll mid = (start+end)>>1;

    update(left, start, mid, i, newvalue);
    update(right, mid+1, end, i, newvalue);

    tree[node] = tree[left]+tree[right];
}

ll query(ll node, ll start, ll end, ll i, ll j)
{
    if(i>end || j<start)
            return 0;
    if(start>=i && end<=j)
            return tree[node];

    ll left = 2*node;
    ll right = 2*node+1;
    ll mid = (start+end)>>1;

    ll x = query(left, start, mid, i, j);
    ll y = query(right, mid+1, end, i, j);

    return (x+y);
}

int main()
{
    FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif /// Mfc_Tanzim

    ll t=1, n, k, m, a, b, c, d;
    //cin >> t;

    while(t--){
             cin >> n >> k;
             for(int i=1; i<=n; i++){
                        cin >> arr[i];
             }
             build(1, 1, n);
             while(k--){
                        cin >> a >> b >> c;
                        if(a==1){
                                update(1, 1, n, b, c);
                        }
                        else{
                                cout << query(1, 1, n, b, c) << endl;
                        }
             }
    }
    return 0;
}
