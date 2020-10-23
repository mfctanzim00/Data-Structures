#include<bits/stdc++.h>
#include<cstring>
//#define Mfc_Tanzim
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define  FastRead  ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;

using namespace __gnu_pbds;
template <typename T> using Set = tree<T, null_type,
                            less<T>, rb_tree_tag,
                            tree_order_statistics_node_update>;
Set<int>s;

int main()
{
    FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif // Mfc_Tanzim

    s.insert(4); ///<==Insert
    s.erase(4);  ///<==Delete
    s.insert(1);
    s.insert(1);
    s.insert(5);
    s.insert(8);

    cout << "Value of 0-th position in the set is: ";
    cout << *s.find_by_order(0) << endl; //<==Find value by rank

    cout << "The position of 9 in the sorted array(set) is: ";
    cout << s.order_of_key(8) << endl; //<==Find value's rank  //indexed from 0

    return 0;
}
