#include <iostream>
#include <vector>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int maxArea(vector<int>& height) {
        
        int left = 0;
        int right = height.size()-1;
        int maxA = 0;
        int curArea = 0;
        
        while(left < right){
            if(height[left] < height[right]){
                curArea = (right-left)*height[left];
                left++;
            }
            else{
                curArea = (right-left)*height[right];
                right--;    
            }
            if(maxA < curArea){
                maxA = curArea;
            }
        }
        return maxA;
}

int main(){	

	//input
	ui T = 0;   //Number of test cases
    ui N = 0;

	cin >> T;
	while(T--){
        vector<int> height;

        cin >> N; //Size of vector
        int temp;

        for(int i=0; i<N; i++){
            cin >> temp;
            height.push_back(temp);
        }

        cout << maxArea(height) << endl;
	}
	return 0;
}