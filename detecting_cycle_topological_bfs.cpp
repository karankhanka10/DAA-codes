#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <queue>

using namespace std;
template<typename T>

class graph
{
    public:
    unordered_map<T,list<T>>adj;
    vector<T>indegree;
    
    void  MakeAdj(int u,int v)
    {
        adj[u].push_back(v);
    }
    
    //code for indegree
    
    void makeindegree()
    {
        for(auto i:adj)
        {
            for(auto j:i.second)
                indegree[j]++;
        }
    }
    
    int bfs(int node)
    {
       int k=0;
        queue<T>q;
        for(int i=0;i<node;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            k++;
            for(auto i:adj[front])
            {
                indegree[i]--;
                if(indegree[i]==0)
                {
                    q.push(i);
                }
            }
        }
        return k;
        
    }
   
};

int main()
{
    graph<int> g;
    int node, edge;
    
    cout<<"enter number of node"<<endl;
    cin>>node;
    cout<<"enter number of edges"<<endl;
    cin>>edge;
    //g.visited = vector<int>(node,0);
    g.indegree = vector<int>(node,0);
    for(int i=0;i<edge;i++)
    {
        int u,v;
        cin>>u>>v;
        g.MakeAdj(u,v);
    }
    g.makeindegree();
    // cout<<"enter starting element you want to traverse through-";
    // int ele;
    // cin>>ele;
   int k = g.bfs(node);
    
    if(k==node)
     cout<<"no cycle";
     else
      cout<<"cycle";
    
    return 0;
}
    
    