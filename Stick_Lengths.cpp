#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n, 0);
    for(int i=0; i<n; i++) cin>>nums[i];
    sort(nums.begin(), nums.end());
    
    int middle = nums[n/2];
    long long cost = 0;
    for(int i=0; i<n; i++) cost += abs(middle - nums[i]);
    cout<<cost;
}