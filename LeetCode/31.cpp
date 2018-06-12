#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void nextPermutation(vector<int>& nums) {
    int len = nums.size();
    int counter = len-2;
    while(counter >= 0 && nums[counter] >= nums[counter+1]){
        counter--;
    }
    if(counter >=0){
        sort(nums.begin()+counter+1, nums.end());
        int index = counter+1;
        while(nums[index] <= nums[counter]) {index++;}
        swap(nums[counter],nums[index]);
    }
    sort(nums.begin()+counter+1, nums.end()); 
}

int main(){	

	//input
	ui T = 0;   //Number of test cases
    ui N = 0;

	cin >> T;
	while(T--){
		vector<int> nums;
        
        cin >> N; //Size of vector
        int temp;

        for(int i=0; i<N; i++){
            cin >> temp;
            nums.push_back(temp);
        }

        nextPermutation(nums);

        cout << "[";
        for(int i=0; i<N; i++){
            cout << nums[i] << ",";
        }
        cout << "]" << endl;
	}
	return 0;
}
