//BFS TRAVERSAL
#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <set>


using namespace std;
template <typename T>
class graph
{
    public:

    unordered_map<T, list<pair<T, T>>>adj;
    vector<T> visited;
    vector<T>distance;
    set<pair<T,T>>st;
    
    void adjListmaker(T u , T v ,T w)
    {
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
         
    }
    
    void dikastra(int source)
    {
        distance[source]=0;
        st.insert(make_pair(0,source)); //dist , node
        while(!st.empty())
        {
            auto top = *(st.begin());  // it will give a pair
            
            int nodedistance = top.first;   
            int topnode = top.second;    
            
            st.erase(top);   //same as pop function in bfs
            
            for(auto i:adj[topnode])   //iterating neighbour of topnode 
            {
                if(nodedistance + i.second < distance[i.first]) // if we got distance less than existing distance we gotta update it.
                {
                    auto record = st.find(make_pair(distance[i.first],i.first));
                    if(record != st.end())    //if record found in set
                    {
                        st.erase(record);  // deleting previous record from set to update record
                    }
                    distance[i.first]=nodedistance + i.second;   //updting new distance 
                    
                    st.insert(make_pair(  distance[i.first],i.first));   //inserting pair of (distance,node) in set
                }
            }
        }
    }
    
    void showResult()
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
        cin>>u>>v>>w;   // w = weight
        g.adjListmaker(u,v,w);
    }
    //cout<<"enter starting node"<<endl;
    int source;
    cout<<"enter source node-";
    cin>>source;
    g.dikastra(source); // sending our source node to the function
    g.showResult();
    return 0;
}