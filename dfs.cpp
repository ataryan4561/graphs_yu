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
void single_source_dfs(vector <vector <int>> &g,int curr,vector <int> &vis,vector <int> &dis, int curr_dis)
    {
        vis[curr]=1;
        dis[curr]=curr_dis;
        for (int child : g[curr])
        {
            if (vis[child]==false)
                single_source_dfs(g,child,vis,dis,curr_dis+1);
        }
    }
bool bipartite(vector<vector<int>> &graph,int curr,int c,vector<int> &col,vector<bool> &vis)
{
    vis[curr]=1;
    col[curr]=c;
    for(int child: graph[curr])
    {
        if(!vis[child])
        {
            if (bipartite(graph,child,!c,col,vis)==false)
                        return false;
        }
        else
        {
            if (col[child]==col[curr])
                    return false;
        }
        return true;
    }
}
bool cycle_detection(vector <vector <int>> &g, int curr, vector<bool> &vis, int par)
    {
        vis[curr]=true;
        for (int child : g[curr])
        {
            if (vis[child]==false )       
            {
                if (cycle_detection(g, child,vis,curr)==true)
                    return true;
            }
            else          
            {
                if (child !=par)     
                {
                    return true;
                }
            }
        }
        return false;
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
        vector<int> vis1(n,0);
        //dfs(graph,0,vis);
        // cout<<connected_components(graph.size(),vis)<<endl;
        // display(); 
        // for display of graph 
        // vector <int> dis(graph.size(),-1);
        // single_source_dfs(graph,1,vis1,dis,0);
        // for (int i=0;i<graph.size();i++)
        //     cout<<i<<"->"<<dis[i]<<endl;
        // vector<int> col(graph.size(),-1);
        // cout<<bipartite(graph,1,0,col,vis);
         cout<<cycle_detection(graph,1,vis,-1);
    }
}