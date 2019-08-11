#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> val,vector<int> weight,int n, int w){
	int K[n+1][w+1];

	for(int i=0;i<=n;++i)
		for(int j=0;j<=w;++j){

			//Base Case
			if(i==0 || j==0) K[i][j]=0;

			//If val[i]>W
			else if(weight[i-1]<=j) K[i][j]=max(val[i-1]+K[i-1][j-weight[i-1]], K[i-1][j]);


			// If val[i]<=W, we can either include
			// ith bag or not for optmal solution
			else
				K[i][j]=K[i-1][j];

		}

	for(int i=0;i<=n;++i){
		for(int j=0;j<=w;++j){
			cout<<K[i][j]<<" ";
		}
		cout<<endl;
	}
	return K[n][w];
}

int main(){
	vector<int> val(3);
	val[0]=60; val[1]=100; val[2]=120;
	vector<int> weight(3);
	weight[0]=1;
	weight[1]=2;
	weight[2]=3;

	cout<<knapsack(val,weight,3,5)<<endl;
}