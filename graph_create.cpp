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
        display(); 
        // for display of graph 
    }
}