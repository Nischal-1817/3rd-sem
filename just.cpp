#include<bits/stdc++.h>
using namespace std;
class graph
{
    private:
        map<int,bool>vis;
        map<int,int>level;
        map<int,map<int,bool>>edges;
        vector<int>adj[20];
    public:
        void bfs(int s)
        {
            int count=0;
            vis[s]=true;
            level[s]=0;
            cout<<s<<" ";
            list<int>q;
            q.push_back(s);
            while(!q.empty())
            {
                count++;
                cout<<"Level "<<count<<":";
                s=q.front();
                q.pop_front();
                for(auto v:adj[s])
                {
                    if(!vis[v])
                    {
                        edges[s][v]=false; edges[v][s]=false;
                        cout<<v<<" ";
                        level[v]=count;
                        vis[v]=true;
                        q.push_back(v);
                    }
                }
                cout<<endl;
            }
        }
        void printLevel()
        {
            cout<<"Levels are:";
            for(auto i=level.begin();i!=level.end();i++)
            {
                cout<<i->first<<":"<<i->second<<'\t';
            }
            cout<<endl;
            for(auto i=edges.begin();i!=edges.end();i++)
            {
                for(auto j=i->second.begin();j!=i->second.end();j++)
                {
                    if(j->second==true)
                    {
                        int x=i->first; int y=j->first;
                        int z=level[x]+level[y];
                        if(z%2==1)
                        {
                            cout<<"There is an even cycle"<<endl;
                            return ;
                        }
                        else if(z%2==0)
                        {
                            cout<<"There is an odd cycle"<<endl;
                            return ;
                        }
                    }
                }
            }
        }
        void addEdge(int u,int v)
        {
            edges[u][v]=true;
            edges[v][u]=true;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
};
int main()
{
    int n,m,u,v;
    graph g;
    cout<<"Enter the number of vertices and edges of the graph:";
    cin>>n>>m;
    cout<<"Enter the edges:";
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        g.addEdge(u,v);
    }
    cout<<"Enter the source vertex:";
    cin>>u;
    g.bfs(u);
    g.printLevel();
    return 0;
}