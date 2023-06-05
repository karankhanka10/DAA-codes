#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <stack>

using namespace std;
template<typename T>

class graph
{
    public:
    unordered_map<T,list<T>>adj;
    vector<T>visited;
   // vector<T>checkparent;
    stack<T>s;
    
    void makeadj(int u,int v)
    {
        adj[u].push_back(v);
    }
    
    void dfs(int k)
    {
        visited[k]=1;
        //checkparent[k]=1;
        for(auto i:adj[k])
        {
            if(!visited[i])
            {
                 dfs(i);
            }
        }
        s.push(k);
       // return false;
    }
    
    void dfscall(int node)
    {
        visited = vector<T>(node,0);
        //checkparent = vector<T>(node,0);
        for(int i=0;i<node;i++)
        {
            if(!visited[i])
            {
               dfs(i);
            }
        }
    }
    
    void printstack()
    {
        while(!s.empty())
       {
           cout<<s.top();
           s.pop();
       }
    }
    
};

int main()
{
    graph<int> g;
    int node,edges;
    cout<<"enter nodes"<<endl;
    cin>>node;
    cout<<"enter edges"<<endl;
    cin>>edges;
    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin>>u>>v;
        g.makeadj(u,v); // for directed graph
    }
    g.dfscall(node);
   g.printstack();
    return 0;
}