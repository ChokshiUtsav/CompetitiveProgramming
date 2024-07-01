/*
Question : 
Given 1D array of chocolates.
array[i] = sweetness of ith chocolate > 0.
You need to split chocolates among k friends (i.e. split array into k subarrays).
Your friends are greedy and they always try to maximize total sweetness given k subarrays.
What would be minimum sweetness you would get , if you are always last person to pick.
*/

#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

/*
Solution Analysis :
Time Complexiy : O(nk) where n is number of chocolates
Space Complexity : O(nk)
*/

int minSweetness(vector<int>& chocolates, int k){

    int n = chocolates.size();
    vector<vector<int>> dp(n,vector<int>(k+1));

    // If there is only one person
    // Then the only way to distribute is to give him all chocolates -> hence sweetness
    int sum = 0;
    for(int i=n-1; i>=0; i--){
        sum += chocolates[i];
        dp[i][1] = sum;
    }

    for(int i=n-1; i>=0; i--){

        // At any point, number of friends left can not be more than number of chocolates
        for(int j=2; j<=k && j<=(n-i); j++){
            int sum = 0;
            dp[i][j] = 0;

            // At any point, number of friends left can not be more than number of chocolates
            for(int l=i; l<n-(j-1); l++){
                sum += chocolates[l];
                dp[i][j] = max(dp[i][j], min(sum,dp[l+1][j-1]));
            }
        }
    }

    return dp[0][k];
}

/*
Solution Analysis :
Time Complexiy : O(nlogM) where M is sum of array, n is number of chocolates
Space Complexity : O(1)
*/

int findParitions(vector<int>& nums, long expSum){
    long curSum = 0;
    int numPartitions = 0;
    for(int i=0; i<nums.size(); i++){
        curSum += nums[i];
        if(curSum >= expSum){
            numPartitions++;
            curSum = 0;
        }
    }
    return numPartitions;
}

int minSweetness_2(vector<int>& chocolates, int k){

    int lo = *min_element(chocolates.begin(), chocolates.end());
    int hi = accumulate(chocolates.begin(), chocolates.end(),0);
    int mid;
    int ans;

    while(lo < hi){
        mid = lo + (hi-lo)/2;

        int numPartitions = findParitions(chocolates,mid);

        if(numPartitions < k){
            hi = mid-1;
        }        
        else{
            ans = mid;
            lo = mid+1;
        }
    }

    return ans;
}

int main(){

    vector<int> chocolates1 = {1,3,2,4,3,2};
    assert(minSweetness(chocolates1,3) == 4);
    assert(minSweetness(chocolates1,2) == 6);
    assert(minSweetness(chocolates1,4) == 2);

    assert(minSweetness_2(chocolates1,3) == 4);
    assert(minSweetness_2(chocolates1,2) == 6);
    assert(minSweetness_2(chocolates1,4) == 2);

    vector<int> chocolates2 = {10,5,8,7};
    assert(minSweetness(chocolates2,2) == 15);
    assert(minSweetness_2(chocolates2,2) == 15);

    return 0;
}