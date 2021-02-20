#include<iostream>
#include<vector>
#include<queue>
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
vector <int> bfs(vector<vector<int>> &g, int N) 
{
    queue <int > q;
    vector <int> bfs;
    vector <int> vis(N,0);
    q.push(0);
    vis[0]=1;
    while (!q.empty())
    {
        int x=q.front();
        q.pop();
        bfs.push_back(x);
        for (int i=0;i<g[x].size();i++)
        {
            if (vis[g[x][i]]!=1)
            {
                q.push(g[x][i]);
                vis[g[x][i]]=1;
            }
        }
    }
    return bfs;
}
void display()
{
    loop(i,graph.size())
    {
        cout<<i<<"->";
        loop(j,graph[i].size())
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}
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
        //display();
        vector<int> ans=bfs(graph,graph.size());
        for(int i=0; i<ans.size(); i++)
        {
            cout<<ans[i]<<" ";
        } 
        cout<<endl;
        // for display of graph 
    }
}