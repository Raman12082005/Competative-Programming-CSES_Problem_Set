#include<bits/stdc++.h>
using namespace std;
// dfs traversal
void dfs(int boss, vector<vector<int>>& adjlist, vector<int>& sub){
    for(int child : adjlist[boss]){
        dfs(child, adjlist, sub);
        sub[boss] += sub[child]+1;
    }
}
int main(){
    //input
    int n;
    cin>>n;
    vector<vector<int>> adjlist(n+1);
    vector<int> sub(n+1, 0);
    for(int i=2; i<=n; i++){
        int parent;
        cin>>parent;

        adjlist[parent].push_back(i);
    }

    dfs(1, adjlist, sub);

    //output
    for(int i=1; i<=n-1; i++){
        cout<<sub[i]<<" ";
    }
    cout<<sub[n];
}