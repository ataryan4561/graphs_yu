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
vector<vector<Edge*>> graph;
int edges;
int n;
class Pair
{
    public:
    int v;
    int av;
    int wt;
    int wsf;
    Pair(int v,int av,int wt,int wsf)
    {
        this->v=v;
        this->av=av;
        this->wt=wt;
        this->wsf=wsf;
    }
};
struct dijikstraComp
{
public:
    bool operator()(Pair &p1, Pair &p2)
    {
        return p1.wsf > p2.wsf;
    }
};
void prims()
{
    cout<<"Here is the Dijikstra implementation"<<endl;
    cout<<"For the MST"<<endl;
    priority_queue<Pair, vector<Pair>, dijikstraComp> pq;
    pq.push(Pair(0,-1,0,0));
    vector<bool> visi(n,false);
    while(pq.size()>0)
    {
        Pair temp=pq.top();
        pq.pop();
        if(!visi[temp.v])
        {
            visi[temp.v]=true;
            if(temp.av!=-1)
            {
                cout<<temp.av<<" "<<temp.v<<" "<<temp.wt<<endl;
            }
            for(Edge* e:graph[temp.v])
            {
                if(!visi[e->v])
                {
                    pq.push(Pair(e->v,temp.v,e->w,e->w+temp.wsf));
                }
            }
        }
        if(pq.size()==1)
        {
            cout<<pq.top().wsf<<endl;
        }
    }
}
void addedges(int u,int v,int w)
{
    graph[u].push_back(new Edge(u,v,w));
    graph[v].push_back(new Edge(v,u,w));
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
    // display();
    prims();
    cout<<endl;
}