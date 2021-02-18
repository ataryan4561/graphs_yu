#include<iostream>
#include<vector>
#define long long ll
#define loop(x,n) for(int x=0; x<n; x++)
using namespace std;
vector<vector<int>> graph;
//declare a graph vector of vector
void addedge(int u,int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
    // for bidirectional graph 
}
void dfs(vector<vector<int>> &graph,int run,vector<bool> &vis)
{
    //cout<<run<<" ";
    vis[run]=true;
    for(int child : graph[run])
    {
        if (!vis[child])
            dfs(graph, child,vis);
    }
}
int connected_components(int n,vector<bool> &vis)
{
    int count=0;
    for(int i=0; i<n; i++)
    {
        if(!vis[i])
        {
            count++;
            dfs(graph,i,vis);
        }
    }
    return count;
}
// void display()
// {
//     loop(i,graph.size())
//     {
//         cout<<i<<"->";
//         loop(j,graph[i].size())
//         {
//             cout<<graph[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }
int main()
{
    int t;
    cin>>t;
    //no of test cases
    while(t--)
    {
        int n;
        cin>>n;
        // no of vertices in graph
        loop(i,n)
        {
            // so that the variable not get dead , push back in it 
            vector<int> ar;
            graph.push_back(ar);
        }
        int edges;
        cin>>edges;
        while(edges--)
        {
        int l,r;
        cin>>l>>r;
        // graph vertices
        addedge(l,r);
        // connect edges 
        }
        vector<bool> vis(n,false);
        //dfs(graph,0,vis);
        cout<<connected_components(graph.size(),vis)<<endl;
        // display(); 
        // for display of graph 
    }
}