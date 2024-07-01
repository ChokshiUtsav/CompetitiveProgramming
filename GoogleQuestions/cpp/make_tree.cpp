/*
Question :
You have a connected undirected graph and Graph has exactly V edges (V = number of vertices)
Convert this graph to tree.
*/

/*
Solution Analysis:
Time Complexity : O(V)
Space Complexity : O(V)
*/

#include <vector>
#include <iostream>

using namespace std;

class Graph{
private:
    int V;
    vector<vector<int>> adjList;
public:
    Graph(int numVertices){
        V = numVertices;
        adjList = vector<vector<int>>(numVertices);
    }

    void addEdge(int u, int v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void removeEdge(int u, int v){
        for(int i=0; i<adjList[u].size(); i++){
            if(adjList[u][i] == v){
                adjList[u].erase(adjList[u].begin()+i);
                break;   
            }
        }
        for(int i=0; i<adjList[v].size(); i++){
            if(adjList[u][i] == u){
                adjList[u].erase(adjList[u].begin()+i);
                break;   
            }
        }
    }

    void dfs(int u, vector<int>& color,int parent){
        color[u] = 1;
        for(int v : adjList[u]){
            if(color[v] == 1 && v != parent){
                //This edge is creating cycle and it needs to be removed
                cout << "Removing edge : " << u << " , " << v << endl;
                removeEdge(u,v);
            }
            else if(color[v] == 0){
                dfs(v,color,u);
            }
        }
        color[u] = 2;
    }

    void make_tree(){

        // 0: WHITE , 1: GRAY, 2: BLACK from CLRS
        vector<int> color(V,0);

        // DFS of always graph produces tree
        for(int u=0; u<V; u++){
            // In case graph is not connected,
            // This algorithm generates forest
            if(color[u] == 0){
                dfs(u,color,-1);
            }
        }
    }
};

int main(){

    /*
            0
           / \
          1   3
         /   / \
        2   4---5
    */

    Graph g1(6);
    g1.addEdge(0,1);
    g1.addEdge(1,2);
    g1.addEdge(0,3);
    g1.addEdge(3,4);
    g1.addEdge(3,5);
    g1.addEdge(4,5);
    g1.make_tree();
    cout << "--------" << endl;

    /*
        ----0
       |   / \
       |  1   3
       | /   / \
        2   4   5
    */

    Graph g2(6);
    g2.addEdge(0,1);
    g2.addEdge(1,2);
    g2.addEdge(0,3);
    g2.addEdge(3,4);
    g2.addEdge(3,5);
    g2.addEdge(0,2);
    g2.make_tree();
}


