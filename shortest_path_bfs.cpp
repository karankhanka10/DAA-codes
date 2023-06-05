//SHORTEST PATH BY BFS UNDIRECTED GRAPH
#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
template<typename T>


class graph
{
  public:
    unordered_map<T, list<T>>adj;
    vector<T>visited;
    vector<T>parent;
    stack<T>ans;
    
     void adjmaker(int u,int v)
     {
         adj[u].push_back(v);
     }
     
     void bfs(int ele)
     {
         queue<T>q;
         q.push(ele);
         visited[ele]=1;
         parent[ele]=-1;
         while(!q.empty())
         {
             int frontq = q.front();
             q.pop();
             for(auto i:adj[frontq])
             {
                 if(!visited[i])
                 {
                     q.push(i);
                     visited[i]=1;
                     parent[i]=frontq;
                 }
             }
         }
         
     }
     
     
     void Shortest_Path(int current , int ele)
     {
         while(current!=ele)
         {
            ans.push(current);
             current = parent[current];
         }
         ans.push(ele);
     }
     
     
    void PrintShortestPath()
    {
        // cout<<"print value"<<endl;
        // cout<<parent[0]<<endl;
        // cout<<parent[1]<<endl;
        // cout<<parent[2]<<endl;
        // cout<<parent[3]<<endl;
        // cout<<parent[4]<<endl;
        // cout<<parent[5]<<endl;
        while(!ans.empty())
        {
            cout<<ans.top()<<"->";
            ans.pop();
        }
    }
};


int main()
{
    graph<int> g;
    int node,edge;
    cout<<"enter node"<<endl;
    cin>>node;
    cout<<"enter edge"<<endl;
    cin>>edge;
    g.visited = vector<int>(node,0);
    g.parent = vector<int>(node,0);
    for(int i=0;i<edge;i++)
    {
        int u,v;
        cin>>u>>v;
        g.adjmaker(u,v);
    }
    
    g.bfs(0);
    g.Shortest_Path(3,0);
    g.PrintShortestPath();
    
    return 0;
}