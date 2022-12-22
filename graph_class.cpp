#include<bits/stdc++.h>
#define long long ll
#define loop(x,n) for(int x=0; x<n; x++)
using namespace std;
class Edge
{
    public:
    int u=0;
    int w=0;
    Edge(int u,int w)
    {
        this->u=u;
        this->w=w;
    }
    Edge()
    {}
};
vector<vector<Edge*>> graph;
void addedges(int u,int v,int w)
{
    graph[u].push_back(new Edge(v,w));
    graph[v].push_back(new Edge(u,w));
}
void display()
{
    for(int i=0; i<graph.size(); i++)
    {
        cout<<i<<"-> ";
        for(int j=0; j<graph[i].size(); j++)
        {
            cout<<graph[i][j]->u<<" , "<<graph[i][j]->w<<" | ";
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
        vector<Edge*> ar;
        graph.push_back(ar);
    }
    int edges;
    cin>>edges;
    while(edges--)
    {
        int l,r,w;
        cin>>l>>r>>w;
        addedges(l,r,w);
    }
    display();
}