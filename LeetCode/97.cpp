#include <iostream>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool solve(string s1, string s2, string s3){
	int l1 = s1.length();
	int l2 = s2.length();
	
	bool** dp = new bool*[l1+1];
	for(int i = 0; i < l1+1; ++i){
			dp[i] = new bool[l2+1];       
	}
	
	dp[0][0] = true;
	
	// fill for s1
	for(int i = 1; i < l1+1; ++i){
		dp[i][0] = false;
		if(dp[i-1][0] == true && s1.at(i-1) == s3.at(i-1)){
			dp[i][0] = true;
		}
	}
	
	// fill for s2
	for(int j = 1; j < l2+1; ++j){
		dp[0][j] = false;
		if(dp[0][j-1] == true && s2.at(j-1) == s3.at(j-1)){
			dp[0][j] = true;
		}
	}
	
	//fill dp
	for(int i=1; i < l1+1; i++){
		for(int j=1; j < l2+1; j++){
			dp[i][j] = false;
			if(dp[i-1][j]==true && s1.at(i-1)==s3.at(i+j-1)){
				dp[i][j] = true || dp[i][j];
			}
			if(dp[i][j-1]==true && s2.at(j-1)==s3.at(i+j-1)){
				dp[i][j] = true || dp[i][j];
			}
		}
	}
	
	return dp[l1][l2];
}

bool isInterleave(string s1, string s2, string s3) {
	
	int l1 = s1.length();
	int l2 = s2.length();
	int l3 = s3.length();
	
	if(l1+l2 != l3){
		return false;
	}
	
	bool ans = solve(s1,s2,s3);
	
	return ans;
}

int main(){	

	//input
	ui T = 0;   //Number of test cases

	string s1,s2,s3;  //Input strings

	cin >> T;
	while(T--){
		cin >> s1 >> s2 >> s3;
		bool ans = isInterleave(s1, s2, s3);
		cout << ans << endl;
	}

	return 0;
}