#include<bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long 	ll;
typedef unsigned long long ull;
typedef long double ld;


//Calculating fast exponential of real base and integer exp.
ld ipow(ld base, ui exp)
{
	ld result = 1.000;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}

//Finding nth root of number using newton raphson formula with given precision
ld findRoot(ui n, ld number, ld precision){

	ld guess = n/2.0;
	ld new_guess;
	ld diff = 1.0;

	while(diff > precision){
		new_guess = ((n-1)*guess + (number/ipow(guess,n-1)))/(ld)n;
		diff = fabs(guess - new_guess);
		guess = new_guess;
	}
	return new_guess;
}


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

		vector<ld> product(N);
		product[0] = (ld)dim[0];
		for(ui i=1; i<N; i++){
			product[i] = (ld)dim[i] * product[i-1];
		}

		cout << "Case #" << caseNumber << ":" << endl;

		for(ui i=0; i<M; i++){
			cin >> L >> R;
			D = R - L + 1;
			if(L == R){
				volume = (ld)dim[L];
			}
			else{
				volume = product[R];
				if(L != 0){
					volume = volume/product[L-1];
				}
			}
			cout << fixed;
			cout << setprecision(9) << findRoot(D,volume,precision) << endl;
		}

		caseNumber++;
	}
	
	return 0;
}