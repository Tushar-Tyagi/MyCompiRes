#include <bits/stdc++.h>

using namespace std;

long long longIncSubs(vector<long long> arr){
    int len=arr.size();
    vector<int> valstore(len);

    for(int i=0;i<len;++i) valstore[i]=1;

    for(int i=1;i<len;++i)
        for(int j=0;j<i;++j){
            if(arr[j]<arr[i]){
                valstore[i]=max(valstore[i],valstore[j]+1);
            }
        }
    return *(max_element(valstore.begin(),valstore.end()));




}


int main(){
    vector<long long> arr= {10,22,9,33,21,50,41,60};
    long long ans=longIncSubs(arr);
    cout<<ans<<endl;
}
