/*
	Recursive Solution:
	If the value of current coin in less than current value, we will recursivelly call the function again with value subtracted.
	if v==0 return 0;
	
	res=INT_MAX
	for(int i=0;i<coinArr.size();++i)
		sub_res=minCoins(coinArr,V-coinArr[i])
		if(sub_res!=INT_MAX && sub_res+1<res)	res=sub_res+1

	return res

	If the solution in a given path doesn't exist, we will need to pass a flag.
	so, we instialize the answer as INT_MAX and after calling function and before updating the res, we check for this.


	Exponential.


		
	*/

//DP 
//O(mV)

#include <bits/stdc++.h>
using namespace std;

int minCoins(vector<int> coins,int m,int V){
	int table[V+1]; //table[i] represents optimal solution for value i.

	table[0]=0;
	for(int i=1;i<=V;++i) table[i]=INT_MAX;

	for(int i=1;i<V+1;++i) //optimal solution for value i/
		for(int j=0;j<m;++j){ //Checking all coins.

			if(coins[j]<=i){
				if(table[i-coins[j]]!=INT_MAX && (table[i-coins[j]]+1 < table[i])) table[i]=table[i-coins[j]]+1;
			}

		}

	return table[V];

}

int main(){
	int arr[]={9,6,5,1};
	vector<int> coins(arr,arr+4);

	int m=4,V=11;
	cout<<minCoins(coins,m,V)<<endl;
}