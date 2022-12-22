#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define long long ll
#define loop(x,n) for (int x=0; x<n; x++)
using namespace std;
vector<vector<int>> graph;
void addedges(int u,int v)
{
    graph[u].push_back(v);
    // graph[v].push_back(u);
}
void dfs(vector<vector<int>> &graph,int src,vector<bool> &vis)
{
    cout<<src;
    for(int child: graph[src])
    {
        if(!vis[child])
        {
            vis[child]=true;
            dfs(graph,child,vis);
        }
    }
}
vector<int> bfs(vector<vector<int>> &graph,vector<bool> &vis)
{
    queue <int> q;
    vector<int> bfs;
    q.push(0);
    vis[0]=1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        bfs.push_back(x);
        for(int i=0; i<graph[x].size(); i++)
        {
            if(!vis[graph[x][i]])
            {
                q.push(graph[x][i]);
                vis[graph[x][i]]=1;
            }
        }
    }
    return bfs;
}
void display()
{
    for(int i=0; i<graph.size(); i++)
    {
        cout<<i<<"-> ";
        for(int j=0; j<graph[i].size(); j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    loop(i,n)
    {
        vector<int> ar;
        graph.push_back(ar);
    }
    int edges;
    cin>>edges;
    while(edges--)
    {
        int l;
        int r;
        cin>>l>>r;
        addedges(l,r);
    }
    display();
    vector<bool> vis(n,false);
    dfs(graph,0,vis);
    cout<<endl;
    vector<bool> vis1(n,false);
    vector<int> ans=bfs(graph,vis1);
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<"";
    }
    cout<<endl;
}