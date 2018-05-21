#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector<vector<int> > threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    set<vector<int> > ans;

    int len = nums.size();
    int init = 0;
    int left = 1;
    int right = len-1;
    int sum;

    for(init=0; init<len; init++){
        right = len-1;
        left = init+1;
        while(left < right){
            sum = nums[init]+nums[left]+nums[right];
            if(sum < 0){
                left++;
            }
            else if(sum > 0){
                right--;
            }
            else{
                vector<int> temp(3,0);
                temp[0] = nums[init];
                temp[1] = nums[left];
                temp[2] = nums[right];
                ans.insert(temp);
                left++;
                right--;
            }
        }
    }
    vector<vector<int> > output(ans.begin(), ans.end());
    return output;
}

int main(){	

	//input
	ui T = 0;   //Number of test cases
    ui N = 0;

	string s;  //Input string

	cin >> T;
	while(T--){
		vector<int> nums;

        cin >> N; //Size of vector
        int temp;

        for(int i=0; i<N; i++){
            cin >> temp;
            nums.push_back(temp);
        }

        vector<vector<int> > res = threeSum(nums);

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
