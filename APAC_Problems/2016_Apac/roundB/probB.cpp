/*
Problem : APAC 2016 University Test : Round B : Problem B : gWheels
Link    : http://code.google.com/codejam/contest/10214486/dashboard#s=p1 
Author  : Utsav Chokshi
Date    : 01/09/2016
*/

/****************************************************
Logic:
X  = Some Pedal Gear
Y1 = Some Extra Gear
Y2 = Another Extra Gear
Z  = Some Tire Gear

We need to solve following equation:
(X*Y1)/(Z*Y2) = P/Q        ;Y1 != Y2

i.e.

=> (X*Q)/(Z*P) = (Y2/Y1)
=> (X/Z)*(Q/P) = (Y2/Y1)

So we can make set of all possible X/Z (X and Z are in smallest form possible i.e. gcd(X,Z) = 1)
We can also make set of all possible Y1/Y2 (Y1 and Y2 is in smallest form and they are not same)

Then Look for pair Y1 = X*Q and Y2 = Z*P

*****************************************************/

#include<bits/stdc++.h>
#define fr freopen("B-large.in","r",stdin)
#define fo freopen("B-large.out","w",stdout)
#define print1(cnt,x) cout<<"Case #"<<cnt++<<": "<<x<<"\n";
#define print2(cnt) cout<<"Case #"<<cnt++<<":"<<"\n";
#define sit set<pair<ull,ull> >::iterator

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;

ull gcd(ull a, ull b){

	if(b == 0){
		return a;
	}
	return gcd(b,a%b);
}

ull reduceFraction(ull *P, ull *Q){
	ull g = gcd(*P,*Q);
	*P =  (*P)/g;
	*Q =  (*Q)/g;
}


int main(){

	//input
	ui T = 0, caseNumber = 1; 
	cin >> T;

	ui Np = 0; // Number of gears at pedal
	ui Ne = 0; // Number of gears at extra
	ui Nt = 0; // Number of gears at tire

	ui M = 0;  //Number of queries
	ull P = 0; //numerator
	ull Q = 0; //denominator

	ull num = 0;
	ull denom = 0;

	while(T--){

		cin >> Np >> Ne >> Nt;

		//Number of teeth
		vector<ull> Tp(Np);
		vector<ull> Te(Ne);
		vector<ull> Tt(Nt);

		set<pair<ull,ull> > TT1;   //stores Tp/Tt
		set<pair<ull,ull> > TT2;   //stores Te1/Te2

		for(ui i=0; i<Np; i++){
			cin >> Tp[i];
		}

		for(ui i=0; i<Ne; i++){
			cin >> Te[i];
		}

		for(ui i=0; i<Nt; i++){
			cin >> Tt[i];
		}

		for(ui i=0; i<Np; i++){
			for(ui j=0; j<Nt; j++){
				num = Tp[i];
				denom = Tt[j];
				reduceFraction(&num,&denom);
				TT1.insert(make_pair(num,denom));
			}
		}

		for(ui i=0; i<Ne; i++){
			for(ui j=0; j<Ne; j++){
				if(i!=j){
					num = Te[i];
					denom = Te[j];
					reduceFraction(&num,&denom);
					TT2.insert(make_pair(num,denom));
				}
			}
		}

		cin >> M;
		bool isPossible = false;
		print2(caseNumber);
		sit it;

		for(ui i=0; i<M; i++){
			cin >> P >> Q;
			
			isPossible = false;
			reduceFraction(&P,&Q);
			
			for(it=TT1.begin(); it!=TT1.end(); it++){
				num = (it->first)*Q;
				denom = (it->second)*P;

				reduceFraction(&num,&denom);

				if(TT2.find(make_pair(num,denom)) != TT2.end()){
					isPossible = true;
					break;
				} 
			}

			if(isPossible){
				cout << "Yes" << endl;
			}
			else{
				cout << "No" << endl;
			}
		}
	}

	return 0;
}