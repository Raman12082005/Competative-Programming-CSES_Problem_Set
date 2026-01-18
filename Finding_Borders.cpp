#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;

    int n = s.size();
    // build lps array
   vector<int> lps(n, 0);
    for(int i=1; i<n; i++){
        int j = lps[i-1];
        while(j>0 && s[i] != s[j]){
            j = lps[j-1];
        }
        if(s[i] == s[j]){
            j++;
        }
        lps[i] = j;
    }

    vector<int> boarder;
    int x = lps[n-1];
    while(x > 0){
        boarder.push_back(x);
        x = lps[x-1];
    }
    reverse(boarder.begin(), boarder.end());
    for(auto it : boarder){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}