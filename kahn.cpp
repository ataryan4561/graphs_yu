#include<bits/stdc++.h>
#define long long ll
#define loop(x,n) for(int x=0; x<n; x++)
using namespace std;
int n;
int edges;
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
vector<vector<Edge*>> graph;
void addedges(int u,int v,int w)
{
    graph[u].push_back(new Edge(u,v,w));
    // graph[v].push_back(new Edge(v,u,w));
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
vector<int> kahn()
{
    vector<int> indegree(n,0);
    vector<int> ans(n,0);
    for(int i=0; i<graph.size(); i++)
    {
        for(int j=0; j<graph[i].size(); j++)
        {
            indegree[graph[i][j]->v]++;
        }
    }
    queue<int> qp;
    for(int i=0; i<graph.size(); i++)
    {
        if(indegree[i]==0)
        {
            qp.push(i);
        }
    }
    int idx=0;
    while(qp.size()>0)
    {
        int temp=qp.front();
        qp.pop();
        ans[idx]=temp;
        idx++;
        for(Edge* e :graph[temp])
        {
            indegree[e->v]--;
            if(indegree[e->v]==0)
            {
                qp.push(e->v);
            }
        }
    }
    if(idx==n)
    {
        return ans;
    }
    vector<int> a(1,-1);
    return a;
}
int main()
{
    cin>>n;
    loop(i,n)
    {
        vector<Edge*> ar;
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
    vector<int> f=kahn();
    for(int i=0; i<f.size(); i++)
    {
        cout<<f[i]<<" ";
    }
    cout<<endl;
}