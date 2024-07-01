/*
Question:
Binary search for an element. 
If element is not present return the closest one.
*/

/*
Solution Analysis :
Time Complexity : O(logn)
Space Complexity : O(1)
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int binary_search(vector<int>& nums, int target){
    int lo = 0;
    int hi = nums.size()-1;

    while(lo <= hi){
        int mid = lo + (hi-lo)/2;
        if(target == nums[mid]){
            return mid;
        }
        else if(target < nums[mid]){
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    return lo;
}

int find_closest_element(vector<int>& nums, int target){

    /*
    In case, you want to use standard lower_bound function from library :
    */
    //int bs_index = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

    int bs_index = binary_search(nums,target);

    if(bs_index == nums.size()){
        return nums.size()-1;
    }
    else if(bs_index == 0){
        return 0;
    }
    else{
        if(abs(nums[bs_index]-target) < abs(nums[bs_index-1]-target)){
            return bs_index;
        }
        else{
            return bs_index-1;
        }
    }
}

int main(){

     // Whenever you write binary search code, always varify against input of size 1 and 2
    vector<int> nums2 = {1};
    assert(find_closest_element(nums2,0) == 0);
    assert(find_closest_element(nums2,1) == 0);
    assert(find_closest_element(nums2,2) == 0);

    vector<int> nums3 = {1,2};
    assert(find_closest_element(nums3,0) == 0);
    assert(find_closest_element(nums3,1) == 0);
    assert(find_closest_element(nums3,2) == 1);
    assert(find_closest_element(nums3,3) == 1);


    vector<int> nums1 = {1,50,100};
    assert(find_closest_element(nums1,49) == 1);
    assert(find_closest_element(nums1,51) == 1);
    assert(find_closest_element(nums1,1) == 0);
    assert(find_closest_element(nums1,50) == 1);
    assert(find_closest_element(nums1,100) == 2);
    assert(find_closest_element(nums1,101) == 2);

    return 0;
}

