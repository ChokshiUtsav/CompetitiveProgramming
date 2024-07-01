/*
Question :
    Given a list of food items and its cost.
    Total money you own : x 
    Find all combination of items which sums to x. 
    Any item can be taken zero or more times.
*/

/*
Solution Analysis :
Time Complexity : 
if cost of items get repeated -> worst case : O(exponenital)
if cost of items does not get repeated -> worst case : O(n*x^2) where n : no of food items
Space Complexity : same as time complexity
 */


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> findAllCombinations(vector<int>& cost, int targetCost){

    unordered_map<int, vector<vector<int>>> costMap;
    costMap[targetCost] = vector<vector<int>>();

    for(int i=0; i<cost.size(); i++){
        for(int c=cost[i]; c<=targetCost; c++){
            
            if(costMap.find(c) == costMap.end()){
                costMap[c] = vector<vector<int>>();
            }

            if(c-cost[i] == 0){
                vector<int> temp = {i};
                costMap[c].push_back(temp);
            }
            else if(costMap.find(c-cost[i]) != costMap.end()){
                for(vector<int> temp : costMap[c-cost[i]]){
                    temp.push_back(i);
                    costMap[c].push_back(temp);
                }
            }
        }
    }

    return costMap[targetCost];
}

void printResult(vector<vector<int>>& result){
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){

    // Assuming food items are sorted by their cost
    vector<int> cost1 = {1,3};
    int targetCost1 = 11;
    vector<vector<int>> result1 = findAllCombinations(cost1,targetCost1);
    printResult(result1);

    vector<int> cost2 = {1,3,3};
    int targetCost2 = 11;
    vector<vector<int>> result2 = findAllCombinations(cost2,targetCost2);
    printResult(result2);
    
    vector<int> cost3 = {1,1,1};
    int targetCost3 = 5;
    vector<vector<int>> result3 = findAllCombinations(cost3,targetCost3);
    printResult(result3);

    vector<int> cost4 = {3,5};
    int targetCost4 = 10;
    vector<vector<int>> result4 = findAllCombinations(cost4,targetCost4);
    printResult(result4);

    return 0;

}