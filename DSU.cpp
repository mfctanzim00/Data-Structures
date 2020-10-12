#include<bits/stdc++.h>
using namespace std;
const int mxn = 1e6;
int parent[mxn];
int child_cnt[mxn];
int find_par(int a)
{
    if(parent[a]==a)
        return parent[a];
    return find_par(parent[a]);
}
void merge_childs(int a,int b)
{
    int x=find_par(a);
    int y=find_par(b);
    if(x!=y)
    {
        if(x>y)
            swap(x,y);
        parent[x]=y;
        child_cnt[y]+=child_cnt[x];
    }
}
Init()
{
    for(int i=1; i<mxn; i++)
    {
        parent[i] = i;
    }
}
int main()
{
    Init();
}

