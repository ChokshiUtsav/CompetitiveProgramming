#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector<vector<int> > fourSum(vector<int>& nums, int target) {
     sort(nums.begin(), nums.end());
        int len = nums.size();
        int left, right, curSum;
        set<vector<int> > result;
        
        for(int i1=0; i1<len-3; i1++){
            for(int i2=i1+1; i2<len-2; i2++){
                left = i2+1;
                right = len-1;
                while(left < right){
                    curSum = nums[i1]+nums[i2]+nums[left]+nums[right];
                    if(curSum < target){
                        left++;
                    }
                    else if(curSum > target){
                        right--;
                    }
                    else{
                        int temp[4] = {nums[i1],nums[i2],nums[left],nums[right]};
                        vector<int> instance(&temp[0], &temp[0]+4);
                        result.insert(instance);
                        left++;
                        right--;
                    }
                }
            }
        }
        
        vector<vector<int> > ans(result.begin(),result.end());
        
        return ans;
}

int main(){	

	//input
	ui T = 0;   //Number of test cases
    ui N = 0;
    int target = 0;

	cin >> T;
	while(T--){
		vector<int> nums;

        cin >> target; //target sum
        cin >> N; //Size of vector
        int temp;

        for(int i=0; i<N; i++){
            cin >> temp;
            nums.push_back(temp);
        }

        vector<vector<int> > res = fourSum(nums, target);

        cout << "[";
        for(int i=0; i<res.size(); i++){
            cout << "[";
            for(int j=0; j<res[i].size(); j++){
                cout << res[i][j] << ",";
            }
            cout << "],";
        }
        cout << "]"<< endl;
	}
	return 0;
}
