#include<bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long 	ll;
typedef unsigned long long ull;
typedef long double ld;

int main(){

	//input
	ui T = 0;   //Number of test cases
	ui caseNumber = 1;

	ui N = 0;  // Number of dimensions
	ui M = 0;  // Number of queries
	
	ui L = 0; //Left of range
	ui R = 0; //Right of range
	ui D = 0; //New Dimension
	ld volume = 0.0; //volume of cuboid (and cube as well)
	ld precision = 1.0e-6;

	cin >> T;

	//logic
	while(T--){
		
		cin >> N >> M;

		vector<ui> dim(N);
		for(ui i=0; i<N; i++){
			cin >> dim[i];
		}

		cout << "Case #" << caseNumber << ":" << endl;

		for(ui i=0; i<M; i++){
			cin >> L >> R;
			D = R - L + 1;
			volume = 0.0;
			for(ui j=L; j<=R; j++){
				volume = volume + log((ld)dim[j]); 
			}

			volume = volume/(ld)D;

			cout << fixed;
			cout << setprecision(9) << exp(volume) << endl;
		}

		caseNumber++;
	}
	
	return 0;
}