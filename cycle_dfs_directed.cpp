#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
using namespace std;
template<typename T>

class graph
{
    public:
  unordered_map<T,list<T>>adj;
 vector<T>visited;
 vector<T>dfsvisit;
  void adjmaker(int u, int v)
  {
      adj[u].push_back(v);
  }
  
  bool dfs(int k)
  {
      visited[k]=1;
      dfsvisit[k] = 1;
      cout<<k<<endl;
      for(auto i:adj[k])
      {
          if(!visited[i])
          {
            bool cycledetected = dfs(i);
            if(cycledetected)
                return true;
          }
           else if(dfsvisit[i])
           {
             return true;
              
            }
          
       }
        dfsvisit[k] = 0;
        return false;
        
  }
  
  int dfscall(int node)
  {
       visited = vector<T>(node, 0);
       dfsvisit = vector<T>(node, 0);
      for(int i=0;i<node;i++)
      {
          if(!visited[i])
          {
           bool cyclefound = dfs(i);
           if(cyclefound)
            return true;
              
          }
           
      }
      return false;
  }
  
};

int main()
{
    int node,edge;
    graph<int> g;
    cout<<"enter node"<<endl;
    cin>>node;
    cout<<"enter edge"<<endl;
    cin>>edge;
    for(int i=0;i<edge;i++)
    {
        int u,v;
        cin>>u>>v;
        g.adjmaker(u,v);
    }
    if(g.dfscall(node))
        cout<<"cycle detected";
    else
        cout<<"cycle not detected";
    return 0;
}
