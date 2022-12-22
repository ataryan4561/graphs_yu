#include<bits/stdc++.h>
#define long long ll
#define loop(x,n) for(int x=0; x<n; x++)
using namespace std;
class Edge
{
    public:
    int u=0;
    int v=0;
    int w=0;
    Edge(int u,int v,int w)
    {
        this->u=u;
        this->v=v;
        this->w=w;
    }
    Edge()
    {}
};
vector<vector<Edge>> graph;
vector<Edge> kruskal_vec;
int n;
int edges;
void addedges(int u,int v,int w)
{
    graph[u].push_back(Edge(u,v,w));
    graph[v].push_back(Edge(v,u,w));
}
bool compare(Edge e1,Edge e2)
{
    return e1.w<e2.w;
}
int findparent(int v,int *parent)
{
    if(parent[v]==v)
    {
        return v;
    }
    return findparent(parent[v],parent);
}
void kruskal()
{
    sort(kruskal_vec.begin(),kruskal_vec.end(),compare);
    vector<Edge> out(n-1);
    int parent[n];
    for(int i=0; i<n; i++)
    {
        parent[i]=i;
    }
    int count=0;
    int i=0; 
    while(count<n-1)
    {
        int sp =findparent(kruskal_vec[i].u,parent);
        int dp =findparent(kruskal_vec[i].v,parent);
        if(sp!=dp)
        {
            out[count]=kruskal_vec[i];
            parent[sp]=dp;
            count++;
        }
        i++;
    }
    cout<<"Here is the MST"<<endl;
    for(int i=0; i<n-1; i++)
    {
        cout<<min(out[i].u,out[i].v)<<" "<<max(out[i].u,out[i].v)<<" "<<out[i].w<<endl;
    }
}
void display()
{
    for(int i=0; i<graph.size(); i++)
    {
        cout<<i<<"-> ";
        for(int j=0; j<graph[i].size(); j++)
        {
            kruskal_vec.push_back(graph[i][j]);
            cout<<graph[i][j].u<<" , "<<graph[i][j].v<<" , "<<graph[i][j].w<<" | ";
        }
        cout<<endl;
    }
}
int main()
{
    cin>>n;
    loop(i,n)
    {
        vector<Edge> ar;
        graph.push_back(ar);
    }
    cin>>edges;
    while(edges--)
    {
        int l,r,w;
        cin>>l>>r>>w;
        addedges(l,r,w);
    }
    display();
    kruskal();
    cout<<endl;
}