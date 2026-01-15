#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long> nums(n, 0);
    long long total = 0;
    for(int i=0; i<n; i++){
        cin>>nums[i];
        total += nums[i];
    }
    
    long long ans = LLONG_MAX;
    for(int mask = 0; mask<(1<<n); mask++){
        long long sum = 0;
        for(int i=0; i<n; i++){
            if(mask & (1<<i)){
                sum += nums[i];
            }
        }
        ans = min(ans, llabs(total-2*sum));
    }
    cout<<ans;
}