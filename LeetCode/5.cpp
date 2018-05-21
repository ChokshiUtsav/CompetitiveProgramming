#include <iostream>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

 string longestPalindrome(string s) {
         
        //length is row and column is index
        int len = s.size();
        int rowCount = len+1;
        bool** mat = new bool*[rowCount];
        for(int i = 0; i < rowCount; i++){
            mat[i] = new bool[len];
        }
        
        for(int i=0; i<2; i++){
            for(int j=0; j<len; j++){
                mat[i][j] = true;
            }
        }


        int maxLen = 1;
        int start = 0;
    
        for(int d=2; d<len+1; d++){
            for(int i=0; i<=(len-d); i++){
                mat[d][i] = false;
                if(s[i]==s[i+d-1] && mat[d-2][i+1]==true){
                    mat[d][i] = true;
                    maxLen = d;
                    start = i;
                }
            }
        }
        string ans = s.substr(start,maxLen);
        return ans;
    }

int main(){	

	//input
	ui T = 0;   //Number of test cases

	string s;  //Input string

	cin >> T;
	while(T--){
		cin >> s;
		string ans = longestPalindrome(s);
		cout << ans << endl;
	}

	return 0;
}