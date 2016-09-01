/*
Problem : APAC 2016 University Test : Round C : Problem B : gFiles
Link    : http://code.google.com/codejam/contest/4284487/dashboard#s=p1 
Author  : Utsav Chokshi
Date    : 01/09/2016
*/

/***********************************************************************
Logic :

Let P = percentage
    K = number of files
    x = total number of files
    Then we need to solve the following equation for each pair of input:
    => Px = 100K
    P is actually floor of some value.
    So Range of values P can take [P,P+1) (including P , but excluding P+1, as floor(P+1) = P+1)
	
	There will be N such equations.
	For each equation, 
	(100K/P+1) < x <= (100K/P)
	So we get two values of x :
	cur_minx = (100K/(P+1))+1  (as x will be greater than this value and also x is integer so next value x can take is exactly one bigger)
	cur_maxx = (100K/P)
	
	After each equation,
	we try to tighten overall range for x.
	so minx = max(minx, cur_minx)
	   maxx = min(maxx, cur_maxx)

	After solving all equations,
	if minx == maxx
	then "answer exists i.e. ans = minx = maxx"
	otherwise "answer does not exist"
************************************************************************/


#include<bits/stdc++.h>
#define fr freopen("B-large.in","r",stdin)
#define fo freopen("B-large.out","w",stdout)
#define print(cnt,x) cout<<"Case #"<<cnt++<<": "<<x<<"\n";

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
ull INF = 1e18;

int main(){

	//input
	ui T = 0, caseNumber = 1; 
	cin >> T;

	ui N = 0;  //Number of status updates
	ull P = 0; //Percentage
	ull K = 0; //Number of files

	ull cur_minx = 0;
	ull cur_maxx = 0;
	ull minx = 0;
	ull maxx = 0;
	bool isPossible = false;
	ll ans = 0;

	while(T--){

		cin >> N;
		isPossible = false;
		minx = 0;
		maxx = INF;
		ans = -1;

		while(N--){
			cin >> P >> K;

			if(!isPossible){
				if(P == 0){
					cur_minx = 100*K + 1;
					cur_maxx = INF;
				}
				else if(P == 100){
					isPossible = true;
					minx = maxx = (100*K)/P;
				}
				else{
					cur_minx = ((100*K)/(P+1)) + 1;
					cur_maxx = (100*K)/P;
				}

				minx = max(minx,cur_minx);
				maxx = min(maxx,cur_maxx);
			}
		}

		if(minx == maxx){
			ans = minx;
		}

		print(caseNumber,ans);
	}

	return 0;
}