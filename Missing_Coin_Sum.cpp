#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n, 0);
    for(int i=0; i<n; i++) cin>>nums[i];
    sort(nums.begin(), nums.end());
    
    long long possum = 1;
    for(auto coin : nums){
        if(coin > possum) break;
        possum += coin;
    }
    cout<<possum;
}