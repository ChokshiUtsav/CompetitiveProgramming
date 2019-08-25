/*
You have been given list of Facebook Logs in following format :
(Timestamp t, Person 1, Person 2) -> Person 1 has become friend with Person 2 at Time t

Find out when was first time, everyone knew everyone.
If areFriends(1,2) = true and areFriends(2,3) = true
then know(1,3) = true and know(3,1) = true
*/

/*
Solution Analysis :
Time Complexity : O(Clog*N) where C is number of connections and N is number of persons
Space Complexity : O(N)
*/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void initialize(vector<int>& parent, vector<int>& size){

    for(int i=0; i<parent.size(); i++){
        parent[i] = i;
        size[i] = 1;
    }
}

// Implemneted using : Path by compression
int root(vector<int>& parent, int n){

    while(parent[n] != n){
        parent[n] = parent[parent[n]];
        n = parent[n];
    }
    return n;
}

int union_by_rank(vector<int>& parent, vector<int>& size, int n1, int n2){
    int root_n1 = root(parent,n1);
    int root_n2 = root(parent,n2);

    if(root_n1 == root_n2){
        return size[root_n1];
    }

    if(size[root_n1] < size[root_n2]){
        parent[root_n1] = root_n2;
        size[root_n2] += size[root_n1];
        return size[root_n2];
    }
    else{
        parent[root_n2] = root_n1;
        size[root_n1] += size[root_n2];
        return size[root_n1];
    }
}

int getTimestamp(int N, vector<pair<int,pair<int,int>>>& connections){

    // For UnionFind Datastructure
    vector<int> parent(N);
    vector<int> size(N);
    initialize(parent,size);

    for(pair<int,pair<int,int>> con : connections){
        int n1 = con.second.first;
        int n2 = con.second.second;
        int result_size = union_by_rank(parent,size,n1,n2);
        if(result_size == N){
            return con.first;
        }
    }

    return -1;
}

int main(){

    vector<pair<int,pair<int,int>>> connections1;
    connections1.push_back(make_pair(1,make_pair(0,1)));
    connections1.push_back(make_pair(2,make_pair(1,2)));
    connections1.push_back(make_pair(3,make_pair(3,4)));
    connections1.push_back(make_pair(4,make_pair(0,2)));
    connections1.push_back(make_pair(5,make_pair(2,3)));
    connections1.push_back(make_pair(6,make_pair(1,3)));
    assert(getTimestamp(5,connections1)==5);

    vector<pair<int,pair<int,int>>> connections2;
    connections2.push_back(make_pair(1,make_pair(1,0)));
    connections2.push_back(make_pair(2,make_pair(0,2)));
    connections2.push_back(make_pair(3,make_pair(3,4)));
    connections2.push_back(make_pair(4,make_pair(1,4)));
    connections2.push_back(make_pair(5,make_pair(2,3)));
    connections2.push_back(make_pair(6,make_pair(1,3)));
    assert(getTimestamp(5,connections2)==4);

    vector<pair<int,pair<int,int>>> connections3;
    connections3.push_back(make_pair(1,make_pair(2,1)));
    connections3.push_back(make_pair(2,make_pair(4,3)));
    connections3.push_back(make_pair(3,make_pair(8,4)));
    connections3.push_back(make_pair(4,make_pair(9,3)));
    connections3.push_back(make_pair(5,make_pair(6,5)));
    connections3.push_back(make_pair(5,make_pair(5,2)));
    assert(getTimestamp(10,connections3)==-1);

    return 0;
}