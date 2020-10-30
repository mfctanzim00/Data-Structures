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
const ll inf = 1<<30;

ll posx[] = {1,-1, 0, 0};
ll posy[] = {0, 0, 1,-1};

struct Tree
{
    ll sum, pref, suff, ans;
}tree[4*mx];
ll arr[mx];

Tree Combine(Tree l, Tree r)
{
    Tree ret;
    ret.sum  = l.sum+r.sum;
    ret.pref = max(l.pref, l.sum+r.pref);
    ret.suff = max(r.suff, r.sum+l.suff);
    ret.ans  = max(l.suff+r.pref, max(l.ans, r.ans));
    return ret;
}

void build(ll node, ll start, ll end)
{
    if(start==end){
            tree[node].sum = tree[node].pref = tree[node].suff = tree[node].ans = max(-inf, arr[start]);
            return;
    }
    ll mid = (start+end)>>1;

    build(node<<1, start, mid);
    build(node<<1|1, mid+1, end);
    tree[node] = Combine(tree[node<<1], tree[node<<1|1]);
}

Tree query(ll node, ll start, ll end, ll i, ll j)
{
    if(i>end || j<start)
            return {-1<<31, -1<<31, -1<<31, -1<<31};
    if(start>=i && end<=j)
            return tree[node];

    ll mid = (start+end)>>1;
    Tree x = query(node<<1, start, mid, i, j);
    Tree y = query(node<<1|1, mid+1, end, i, j);

    return Combine(x, y);
}

void update(ll node, ll start, ll end, ll i, ll newvalue)
{
    if(i<start || i>end)
             return;
    if(start>=i && end<=i){
             tree[node].sum = tree[node].pref = tree[node].suff = tree[node].ans = max(-inf, newvalue);
             return;
    }
    ll mid = (start+end)>>1;

    update(node<<1, start, mid, i, newvalue);
    update(node<<1|1, mid+1, end, i, newvalue);
    tree[node] = Combine(tree[node<<1], tree[node<<1|1]);
}

int main()
{
    //FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif /// Mfc_Tanzim

    ll t=1, n, q, l, r, type, pos, value;
    //cin >> t;

    while(t--){
             scanf("%lld", &n);
             for(ll i=1; i<=n; i++){
                        scanf("%lld", &arr[i]);
             }
             build(1, 1, n);
             scanf("%lld", &q);
             while(q--){
                        scanf("%lld", &type);
                        if(type==0){
                                  scanf("%lld %lld", &pos, &value);
                                  update(1, 1, n, pos, value);
                        }
                        else{
                                  scanf("%lld %lld", &l, &r);
                                  ll ret = query(1, 1, n, l, r).ans;
                                  printf("%lld\n", ret);
                        }
             }
    }
    return 0;
}

