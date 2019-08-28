/*
Question :
Check whether given graph is bipartite.
Put constraints :
Graph is undirected (can have multiple components)
*/

/*
Solution Analysis :
Time Complexity : O(v^2) where V is number of vertices
Space Complexity : O(V)
*/

#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

/*
This algo also works for Directed Graph with multiple Strongly Connected Components
*/
bool dfs(vector<vector<int>>& adjList, int u, vector<int>& colorSet,int color){

    if(colorSet[u] != -1){
        return (colorSet[u] == color);
    }

    colorSet[u] = color;

    for(int v : adjList[u]){
        if(dfs(adjList,v,colorSet,(color+1)%2) == false){
            return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& adjList){

    int V = adjList.size();
    vector<int> colorSet(V,-1);

    for(int i=0; i<V; i++){
        if(colorSet[i] == -1 && (dfs(adjList,i,colorSet,0) == false)){
            return false;
        }
    }
    return true;
}

int main(){

    // Regular Bipartite Graph
    vector<vector<int>> adjList1 = {{1},{0,3,4},{4},{1},{1,2}};
    assert(isBipartite(adjList1) == true);

    // Graph without edges is also bipartite
    vector<vector<int>> adjList2 = {{},{},{},{},{}};
    assert(isBipartite(adjList2) == true);

    // Graph with cycle (even number of vertex) is also bipartite
    vector<vector<int>> adjList3 = {{1,3},{0,2},{1,3},{0,2}};
    assert(isBipartite(adjList3) == true);

    // Graph with cycle (odd number of vertex) is  not bipartite
    vector<vector<int>> adjList4 = {{1,4},{0,2},{1,3},{2,4},{3,0}};
    assert(isBipartite(adjList4) == false);

    // Graph with multiple components
    vector<vector<int>> adjList5 = {{1},{0},{3,4},{2},{2}};
    assert(isBipartite(adjList5) == true);


    
    return 0;
}