/*
Question : 
    N people running a race. 
    You are given an input array where the value input[i]=j denotes that player i finished just after j. 
    If player wins race then input[i] = -1
    Print players in order of their finishing.
 */

/*
Solution Analysis :
Time Complexity : O(n)
Space Complexity : O(n)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<int> getFinishingOrder(vector<int> input){
    vector<int> result(input.size());
    unordered_map< int,vector<int> > depMap;
    queue<int> q;

    // Traverse array , populate winners into queue and prepare dependency map
    for(int i=0; i<input.size(); i++){
        if(input[i] == -1){
            q.push(i);
        }
        else{
            if(depMap.find(input[i]) == depMap.end()){
                depMap[input[i]] = vector<int>();
            }
            depMap[input[i]].push_back(i);
        }
    }

    // Perform level order traversal
    int index = 0;

    while(!q.empty() && index < input.size()){
        result[index] = q.front();
        q.pop();

        if(depMap.find(result[index]) != depMap.end()){
            for(int l : depMap[result[index]]){
                q.push(l);
            }
        }
        index++;
    }

    if(index < result.size()){
        cout << "Bad Input" << endl;
        //throw invalid_argument("Bad input");
    }

    return result;
}

int main(){

    // Correct Inputs
    vector<int> input1 {-1, 0, 1, 2, 3, 4};
    vector<int> result1 = getFinishingOrder(input1);
    assert(result1 == vector<int>({0, 1, 2, 3, 4, 5}));

    vector<int> input2 = {4, 3, 6, -1, 2, 1, 5};
    vector<int> result2 = getFinishingOrder(input2);
    assert(result2 == vector<int>({3, 1, 5, 6, 2, 4, 0}));

    vector<int> input3 = { 2, 2, -1, 2, 2};
    vector<int> result3 = getFinishingOrder(input3);
    assert(result3 == vector<int>({2, 0, 1, 3, 4}));

    vector<int> input4 = { 2, 2, -1, 2, 2};
    vector<int> result4 = getFinishingOrder(input4);
    assert(result4 == vector<int>({2, 0, 1, 3, 4}));
    
    vector<int> input5 = {3, 0, 3, -1 , 2, 4};
    vector<int> result5 = getFinishingOrder(input5);
    assert(result5 == vector<int>({3, 0, 2, 1, 4, 5}));

    // Bad Inputs
    vector<int> input6 = { 2, 0, 1 };
    vector<int> result6 = getFinishingOrder(input6);

    vector<int> input7 = { -1, -1, -1, 5, 5, 3};
    vector<int> result7 = getFinishingOrder(input7);
    
    return 0;
}