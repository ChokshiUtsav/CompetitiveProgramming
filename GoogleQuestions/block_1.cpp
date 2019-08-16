/*
Question :
You have an array of length L.
You have another array of integers which denote size of blocks.
You have to fit these blocks in same order in the above array of length L.
There should be atleast one gap between each block.
Create a boolean function which returns true if there is exactly one way to fill it.

Example. L=6, arr=(2,3)
You can fill the array in exactly one way i.e. (*,*,_,*,*,*) 
So function returns true
*/

/*
Solution Analysis :
Time Complexity : O(n) where n = number of blocks
Space Complexity : O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

bool canFillArray(vector<int>& blocks, int L){

    int sum = 0;
    for(int blockSize : blocks){
        sum += blockSize;
    }

    return ((sum+blocks.size()-1) == L);
}

int main(){

    // Positive Test Cases
    vector<int> blocks1 = {2,3};
    int L1 = 6;
    assert(true == canFillArray(blocks1,L1));
    
    // Negative Test Cases
    vector<int> blocks2 = {2,3};
    int L2 = 7;
    assert(false == canFillArray(blocks2,L2));

    vector<int> blocks3 = {2,3};
    int L3 = 4;
    assert(false == canFillArray(blocks3,L3));

    return 0;
}