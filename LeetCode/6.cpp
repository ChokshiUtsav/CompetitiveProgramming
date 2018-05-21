#include <iostream>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string convert(string s, int numRows) {
        
        if(numRows == 1){
            return s;
        }
        
        string ans = s;
        int len = s.size();
        int magicNum = 2*(numRows-1);
        int counter = 0;
        for(int i=0; i<numRows; i++){
            int diff = 2*i;
            int index = i;
            while(index < len){
                diff = magicNum - diff;
                if(diff != 0 ){
                    ans[counter] = s[index];
                    counter++;
                }
                index = index + diff;
            }            
        }
        return ans;
    }

int main(){	

	//input
	ui T = 0;   //Number of test cases

	string s;  //Input string
    int rows;  //Input num of rows

	cin >> T;
	while(T--){
		cin >> s >> rows;
		string ans = convert(s,rows);
		cout << ans << endl;
	}

	return 0;
}