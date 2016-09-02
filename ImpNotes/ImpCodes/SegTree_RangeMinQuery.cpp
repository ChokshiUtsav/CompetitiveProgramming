//From TusharRoy's lecture

#include<bits/stdc++.h>
#define arr_size 5
#define inf 1e8

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ui nextPowerOf2(ui n)
{
    ui power = 1;
    if (n != 0 && (n & (n - 1)) == 0){
        return n;
    }
 
    while (power < n) {
        power <<= 1;
    }

    return power;
}

void buildSegTree(int* arr,vector<int>& segtree,int low, int high, int root){

	if(low == high){
		segtree[root] = arr[low];
		return;
	}

	int mid = (low+high)/2;
	int lc = 2*root+1;
	int rc = 2*root+2;

	buildSegTree(arr,segtree,low,mid,lc);
	buildSegTree(arr,segtree,mid+1,high,rc);

	segtree[root] = min(segtree[lc], segtree[rc]);
}

int rangeMinQuery(vector<int>& segtree,int qLow, int qHigh, int low, int high, int root){

	//Total Overlap
	if(qLow<=low && qHigh>=high){
		return segtree[root];
	}
	
	// No Overlap
	if(high<qLow || low>qHigh){
		return inf;
	}
	
	//Partial Overlap	
	int mid = (low+high)/2;
	int lc = 2*root+1;
	int rc = 2*root+2;
	int lcmin = rangeMinQuery(segtree,qLow,qHigh,low,mid,lc);
	int rcmin = rangeMinQuery(segtree,qLow,qHigh,mid+1,high,rc);
	
	return min(lcmin,rcmin); 
}


int main(){

	int arr[arr_size] = {-1,3,0,1,2};
	int len = (2*nextPowerOf2(arr_size))-1;
	vector<int> segtree(len,inf);

	buildSegTree(arr,segtree,0,arr_size-1,0);

	cout << rangeMinQuery(segtree,1,3,0,4,0) << endl;

	return 0; 
}