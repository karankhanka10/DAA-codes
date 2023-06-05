//BFS TRAVERSAL
#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
#include <list>


using namespace std;
template <typename T>
class graph
{
    public:

    unordered_map<T, list<pair<T, T>>>adj;
    vector<T> visited;
    vector<T>distance;
    stack<T>s;
    void adjListmaker(T u , T v ,T w)
    {
        pair<int,int> p = make_pair(v,w);
        adj[u].push_back(p);
         
    }
    
    void dfs(T n)
    {
        visited[n]=1;
       // cout<<n;
       for(auto i:adj[n])
       {
           if(!visited[i.first])
                dfs(i.first);
       }
       s.push(n); 
    }
    void dfscall(T node)
    {
        for(int i=0;i<node;i++)
        {
            if(!visited[i])
                dfs(i);
        }
    }
    
    void shortest_path(int start)
    {
        distance[start]=0;
        
        while(!s.empty())
        {
            int top = s.top();
            s.pop();
            if(distance[top]!=999)
            {
                for(auto i:adj[top])
                {
                    if(distance[top]+i.second  < distance[i.first])
                    {
                        distance[i.first]= distance[top]+i.second;
                    }
                }
            }
        }
    }
    
    void print_shortest_path()
    {
        for(auto i:distance)
        {
            cout<<i<<" ";
        }
    }

    
};
int main()
{
    graph<int> g;
    int node,edge;
    int u,v,w;
    cout<<"enter number of nodes"<<endl;
    cin>>node;
    cout<<"enter number of edges"<<endl;
    cin>>edge;
    g.visited = vector<int>(node,0);
    g.distance = vector<int>(node,999);
    for(int i=0;i<edge;i++)
    {
        cin>>u>>v>>w;
        g.adjListmaker(u,v,w);
    }
    //cout<<"enter starting node"<<endl;
    g.dfscall(node);
    g.shortest_path(1);
    g.print_shortest_path();
    return 0;
}