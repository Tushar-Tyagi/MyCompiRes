#include <bits/stdc++.h>

using namespace std;

int kadane(vector<int> arr){
	int Max=arr[0];
	int max_so_far=arr[0];

	int n=arr.size();
	for(int i=1;i<n;++i){
		max_so_far=max(arr[i],arr[i]+max_so_far);
		Max=max(Max,max_so_far);
	}
	return Max;
}

int main(){
	int x[]={-2,-3,4,-1,-2,1,5,-3};
	vector<int> arr(x,x+8);

	cout<<kadane(arr)<<endl;
}