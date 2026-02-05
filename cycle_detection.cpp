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

    // void bfs(){
    //     queue<int>q;
    //     vector<bool>vis(V, false);
    //     q.push(0);
    //     vis[0] = true;
    //     while(q.size() > 0){
    //         int u = q.front();
    //         q.pop();
    //         cout<<u<<" ";
    //         for(int v : l[u]){
    //             if(!vis[v]){
    //                 vis[v] = true;
    //                 q.push(v);
    //             }
    //         }
    //     }

    // }
    // void print(){
    //     for(int i = 0; i < V; i++){
    //         cout<<i<<" : "<<" ";
    //         for(int neigh : l[i]){
    //             cout<<neigh<<", ";
    //         } 
    //         cout<<endl;
    //     }
    // }

    // cycle detection in an undirected graph - using DFS algo 

    bool isCycleUndirDFS(int src, int par, vector<bool>&vis){
        vis[src] = true;
        list<int>neighbors = l[src];

        for(int v : neighbors){
            if(!vis[v]){
                if(isCycleUndirDFS(v, src, vis)){
                    return true;
                }
            }
            else if(v != par){
                return true;
            }
        }
    }

    bool isCycle(){
        vector<bool> vis(V, false);

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(isCycleUndirDFS(i, -1, vis)){
                    return true;
                }
            }
        }
        return false;
    }
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

    // g.print();
    cout<<g.isCycle();

    // g.bfs();



    
    return 0;
}