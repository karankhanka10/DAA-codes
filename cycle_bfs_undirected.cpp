#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <list>

using namespace std;

template<typename T>

class graph {
public:
    vector<T> visited;
    unordered_map<T, list<T>> adj;
    vector<T> ans;
    unordered_map<T,T> parent;

    void makeadj(T u, T v, bool direction) {
        adj[u].push_back(v);
        if(direction==0)
            adj[v].push_back(u);
    }

    int bfs(int node) {
        parent[node]=-1;
        int flag= 0;
        queue<T>q;
        q.push(node);
        visited[node]=1;
        while(!q.empty() && !flag)
        {
            int frontq = q.front();
            q.pop();
            ans.push_back(frontq);
            for(auto i:adj[frontq])
            {
                if(visited[i]==1 && i!=parent[frontq])
                {
                    flag = 1;
                    break;
                }
                else if(!visited[i])
                {
                    q.push(i);
                    visited[i]=1;
                    parent[i]= frontq;
                }
            }
        }
        return flag;
    }
};

int main() {
    int node, edge;
    cout<<"enter node "<<endl;
    cin>>node;
    cout<<"enter edge "<<endl;
    cin>>edge;
    graph<int> g;
    g.visited = vector<int>(node, 0);  // initialize visited vector based on node count
    for(int i=0;i<edge;i++) {
        int u, v;
        cin>>u>>v;
        g.makeadj(u, v, 0);
    }
      int  flag;
    for (int i = 0; i < node; i++) {
        if (!g.visited[i]) {
          flag = g.bfs(i);  // start BFS from every unvisited node
        }
    }
    if(flag==1)
            cout<<"cycle exists"<<endl;
        else
            cout<<"cycle doesn't exist"<<endl;
    return 0;
}
