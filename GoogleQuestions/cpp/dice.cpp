/*
Question: 
You have N dices. Each dice has M faces (numbered from 1 to M) 
Find number of ways to throw dices such that sum = X 
*/

/*
Similar LeetCode Problems : 
https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
*/

/*
Time Complexity : O(N*X)
Space Complexity : O(N*X)
*/


#include <iostream>
#include <vector>

using namespace std;

int numberOfWaysToRoll(int N, int M, int X){

    // If X is greater than maximum/minimum value possible 
    if(X > N*M || X < N){
        return 0;
    }

    vector<vector<int>> dp(N,vector<int>(X+1,0));

    //If we have only one dice, we can get sum from 1 to M only
    for(int j=1; j<=min(M,X); j++){
        dp[0][j] = 1;
    }

    for(int i=1; i<N; i++){
        for(int j=1; j<=X; j++){
            // Let's assume that dice i has face value = 1
            // then in order to find number of ways of having sum = j using dice (0,i)
            // we need to look at, number of ways of making sum j-1 using previous dices (0,i-1) 
            dp[i][j] = dp[i-1][j-1];

            // Also we are able to make sum j-1 using dice (0,i) in "y" number of ways
            // Then we should be able to make sum j using dice (0,i) in "y" number of ways
            // As we'll only need to have +1 face value on current dice to do that
            dp[i][j] += dp[i][j-1];

            //But we'll exceed face value M if sum j-1 was made with face value M for some ways
            //So we need to subtract those ways
            //This scenario happens when your sum is strictly greater than face value M only 
            if(j-1-M > 0){
                dp[i][j] -= dp[i-1][j-1-M];
            }
        }
    }

    return dp[N-1][X];
}

int main(){

    assert(numberOfWaysToRoll(2,6,12) == 1);
    assert(numberOfWaysToRoll(2,6,7) == 6);
    assert(numberOfWaysToRoll(2,6,6) == 5);
    assert(numberOfWaysToRoll(2,6,5) == 4);
    assert(numberOfWaysToRoll(2,6,8) == 5);
    assert(numberOfWaysToRoll(2,6,9) == 4);

    assert(numberOfWaysToRoll(2,6,1) == 0);
    assert(numberOfWaysToRoll(2,6,14) == 0);

    assert(numberOfWaysToRoll(10,6,40) == 2930455);

    return 0;
}