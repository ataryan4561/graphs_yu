#include<iostream>
#include<vector>
#define long long ll
#define loop(x,n) for(int x=0; x<n; x++)
using namespace std;
// vector<vector<int>> graph;
vector<vector<Edge*>> graph;
// class inpi.
class Edge
{
    public:
    int v = 0;
    int w = 0;

    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
}
//declare a graph vector of vector
void addedge(int u,int v,int w)
{
    graph[u].push_back(v,w);
    graph[v].push_back(u,w);
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
        addedge(l,r,10);
        // connect edges 
        }
        display(); 
        // for display of graph 
    }
}