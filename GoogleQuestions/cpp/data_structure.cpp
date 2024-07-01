/*
Question : 
Create data structure that supports following operations :
1) InsertOrReplace(index, value)
2) FindSmallestIndexFor(value)

Both index and value are integers
*/

/*
Solution Analysis :
Time Complexity :
1) InsertOrReplace -> O(logn)
2) FindSmallestIndexFor -> O(logn)

Space Complexity :
O(n)
*/

/* 
Alternate Solution Analysis :
If we would have used mean heap(i.e. priority_queue) for storing index against values then
Time Complexity :
1) InsertOrReplace -> O(n) as deleting element from min heap takes O(n)
2) FindSmallestIndexFor -> O(1)

If we would have used hash set(i.e. unordered_set) for storing index against values then
Time Complexity :
1) InsertOrReplace -> O(1)
2) FindSmallestIndexFor -> O(n) as finding min element from hash set takes O(n)

*/

#include <iostream>
#include <set>
#include <unordered_map>


using namespace std;

class BidirectionalMap{

private:
    unordered_map<int,int> indexMap;
    unordered_map<int,set<int>> valueMap;

public:

    void insertOrReplace(int index, int value){

        if(indexMap.find(index) != indexMap.end()){
            int oldValue = indexMap[index];
            valueMap[oldValue].erase(index);
        }
        indexMap[index] = value;

        if(valueMap.find(value) == valueMap.end()){
            valueMap[value] = set<int>();
        }
        valueMap[value].insert(index);
    }

    int findSmallestIndexFor(int value){

        if(valueMap.find(value) == valueMap.end() || valueMap[value].empty()){
            return -1;
        }
        
        return *valueMap[value].begin();
    }
};

int main(){

    BidirectionalMap bidiMap;

    bidiMap.insertOrReplace(0,200);
    bidiMap.insertOrReplace(2,100);
    bidiMap.insertOrReplace(1,100);
    assert(1 == bidiMap.findSmallestIndexFor(100));
    assert(-1 == bidiMap.findSmallestIndexFor(99));
    
    bidiMap.insertOrReplace(0,100);
    assert(0 == bidiMap.findSmallestIndexFor(100));
    assert(-1 == bidiMap.findSmallestIndexFor(200));

    return 0;
}