#include<bits/stdc++.h>
using namespace std;
// void helper(string str, int n){
//     // base cases
//     if(str.size() == n){
//         cout<<str<<endl;
//         return;
//     }
    
//     helper(str+'0', n);
//     helper(str+'1', n);
// }
int main(){
    int n;
    cin>>n;
    
    // string str = "";
    // helper(str, n);
    
    int total = (1<<n);
    for(int i=0; i<total; i++){
        int gray = i ^ (i>>1);
        
        for(int j=n-1; j>=0; j--){
            cout<<((gray>>j)&1);
        }
        cout<<endl;
    }
}