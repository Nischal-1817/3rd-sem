#include<bits/stdc++.h>
using namespace std;
class graph 
{
    private:
        int vertices,edges;
        vector<int> adj[21];
        vector<bool> vis;
        vector<int> dis;
    public:
        void dfs(vector<int>adj[],int s)
        {
            for(auto v:adj[s])
            {
                if(vis[v]) continue;
                vis[v]=true;
                dis[v]=dis[s]+1;
                cout<<v<<" ";
                dfs(adj,v);
            }
        }
        void create(int n,int m)
        {
            vertices=n; edges=m;
            int u,v;
            cout<<"Enter the edges:";
            for(int i=0;i<vertices;i++)
            {
                cin>>u>>v;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            cout<<"1"<<" ";
            vis[1]=true;
            dfs(adj,1);
        }

};
int main()
{
    int n,m;
    cout<<"Enter the number of verices and edges:";
    cin>>n>>m;
    graph g;
    g.create(n,m);
    return 0;
}