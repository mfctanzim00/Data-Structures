
/* Problem Link (Course Schedule) : https://cses.fi/problemset/task/1679/ */

#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> graph[1000000];
int visited[1000000];///this one is used for detecting Cycle
bool vis[1000000];

stack<int>s;

bool cycleFound(int src)
{
    if(visited[src]==1)
        return true;
    if(visited[src]==2)
        return false;

    visited[src]=1;
    for(auto v: graph[src])
        if(cycleFound(v))
            return true;

    visited[src]=2;
    return false;
}
bool detectCycle()
{
    for(int u=1; u<=n; u++)
        if(!visited[u])
            if(cycleFound(u))
                return true;
    return false;
}

void Dfs(int u)
{
    vis[u]=true;
    for(auto v: graph[u])
        if(!vis[v])
            Dfs(v);
    s.push(u);
}

int main ()
{
    //freopen("input.txt", "r", stdin);
    int m, u, v;
    cin >> n >> m;
    while(m--)
    {
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for(int i=1; i<=n; i++)
        if(!vis[i])
            Dfs(i);

    if(detectCycle())
        cout << "IMPOSSIBLE" << endl;
    else
    {
        while(!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
}
