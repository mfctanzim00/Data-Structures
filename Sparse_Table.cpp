/*
     Problem Link:https://www.spoj.com/problems/RMQSQ/
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

int table[mx][500]; ///log of mx

void buildSparseTable(int arr[], int n)
{
    for(int i=0; i<n; i++)
        table[i][0] = arr[i];

    for(int j=1; (1<<j)<=n; j++)
        for(int i=0; (i+(1<<j)-1)<n; i++)
            table[i][j] = max(table[i][j-1], table[i+(1<<(j-1))][j-1]);
}

int query(int l, int r)
{
    if(l>r)swap(l, r);

    int j = log2(r-l+1);
    return max(table[l][j], table[r-(1<<j)+1][j]);
}

int main()
{
    FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif /// Mfc_Tanzim

	int n, q, l, r;
	cin >> n;

	int arr[n+1];
	for(int i=0; i<n; i++){
            cin >> arr[i];
	}
	buildSparseTable(arr, n);

	cin >> q;
	while(q--){
            cin >> l >> r;
            cout << query(l, r) << endl;
	}
	return 0;
}
