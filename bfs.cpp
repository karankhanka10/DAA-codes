//BFS TRAVERSAL
#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <list>



using namespace std;
template <typename T>
class graph
{
    public:
    int n=6;
    unordered_map<T, list<T>>adjList;
    vector<T> visited;
    vector<T> ans;
    
    void adjListmaker(T u , T v , bool direction)
    {
        adjList[u].push_back(v);
        if(direction==0)
             adjList[v].push_back(u);
    }
    
    //  void printAdjList()
    // {
    // for(auto i:adjList)
    // {
    //     cout<<i.first<<"->";
    //     for(auto j:i.second)
    //     {
    //         cout<<j<<",";
    //     }
    //     cout<<endl;
    // }
    // }
    
    void bfs(T n)
    {
        queue<T>q;
        q.push(n);
        visited[n]=1;
        while(!q.empty())
        {
            int frontnode = q.front();
            q.pop();
            
            // store it in ans
            ans.push_back(frontnode);
            
            for(auto i:adjList[frontnode])
            {
                if(!visited[i] )
                {
                    q.push(i);
                    visited[i]=1;
                }
            }
        }
        // cout<<"bfs";
        // cout<<ans[2];
    }
    void printans(int edge)
    {
        for(int i=0;i<edge;i++)
    {
        cout<<ans[i]<<endl;
    }
    }
};
int main()
{
    graph<int> g;
    int node,edge;
    int u,v;
    cout<<"enter number of nodes"<<endl;
    cin>>node;
    cout<<"enter number of edges"<<endl;
    cin>>edge;
    for(int i=0;i<edge;i++)
    {
        
        cin>>u>>v;
        g.adjListmaker(u,v,0);
    }
     //g.printAdjList();
    int n;
    cout<<"enter starting node"<<endl;
    cin>>n;
    g.bfs(n);
   // cout<<"size is"<<endl;
    g.printans( node);
    return 0;
}