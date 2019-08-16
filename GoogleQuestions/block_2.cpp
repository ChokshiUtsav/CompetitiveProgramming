/*
Question (Last question continued..) :
You have an array of length L.
You have another array of integers which denote size of blocks.
You have to fit these blocks in same order in the above array of length L.
There should be atleast one gap between each block.
Write function that 
find all the position in array which won't be empty for any configuration, if there is a free space left.
*/

/*
Solution Analysis :
Time Complexity : O(n) where n = number of blocks
Space Complexity : O(1)
*/

#include <vector>
#include <iostream>

using namespace std;

vector<int> findAllNonEmptyPositions(vector<int> blocks, int L){

    vector<int> result;

    // Find out free spaces
    int totalBlocks = 0;
    for(int b : blocks){
        totalBlocks += b;
    }
    int freeSpaces = L - totalBlocks - (blocks.size()-1);
    

    // If there are zero or more freespaces then & only then one or more configuration is possible
    if(freeSpaces >= 0){
        int startIndex = 0;
        for(int blockSize : blocks){
            int endIndex = startIndex+blockSize+freeSpaces;
            for(int index = startIndex+freeSpaces; index < endIndex-freeSpaces; index++){
                result.push_back(index);
            }
            startIndex += blockSize + 1;
        }
    }

    return result;
}

int main(){

    vector<int> blocks1 = {2,3};
    int L1 = 6;
    vector<int> result1 = findAllNonEmptyPositions(blocks1,L1);
    assert(result1 == vector<int>({0,1,3,4,5}));

    vector<int> blocks2 = {2,3};
    int L2 = 7;
    vector<int> result2 = findAllNonEmptyPositions(blocks2,L2);
    assert(result2 == vector<int>({1,4,5}));

    vector<int> blocks3 = {2,3};
    int L3 = 4;
    vector<int> result3 = findAllNonEmptyPositions(blocks3,L3);
    assert(result3 == vector<int>({}));


    return 0;
}