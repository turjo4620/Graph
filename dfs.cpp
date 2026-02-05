#include<bits/stdc++.h>

using namespace std;

class Graph{
    int V;
    list<int>*l;
    // int * arr; --- just eirokom e same, dynamic memory nisi cuz vertices ta ekkekbar ekerokom hotei pare.! right?
public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
        // arr = new int[size]
    }

    // adding edge - undirected 
    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }


    // DFS - helper

    void dfs_helper(int u, vector<bool>&vis){
        cout<<u<<" ";
        vis[u] = true;

        for(int v : l[u]){
            if(!vis[v]){
                dfs_helper(v, vis);
            }
        }
    }
    
    void dfs(){
        int src = 0;
        vector<bool>vis(V, false);

        dfs_helper(src, vis);
        cout<<endl;
    }

    // void print(){
    //     for(int i = 0; i < V; i++){
    //         cout<<i<<" : "<<" ";
    //         for(int neigh : l[i]){
    //             cout<<neigh<<", ";
    //         } 
    //         cout<<endl;
    //     }
    // }
};

int main(){
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 6);
    g.addEdge(6, 5);
    g.addEdge(5, 3);
    g.addEdge(5, 4);
    g.addEdge(3, 4);

    g.dfs();

    // g.print();

    
    return 0;
}