#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> tree(200000+1);
vector<bool> visited(200000+1, false);
int maxdist = 0;
int farnode = 0;

void dfs(int node, int dist){
    visited[node] = true;

    if(dist > maxdist){
        maxdist = dist;
        farnode = node;
    }

    for(auto neighbour : tree[node]){
        if(!visited[neighbour]){
            dfs(neighbour, dist+1);
        }
    }
}
int main(){
    int n;
    cin>>n;

    for(int i=0; i<n-1; i++){
        int u, v;
        cin>>u>>v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1, 0);

    fill(visited.begin(), visited.end(), false);

    dfs(farnode, 0);

    cout<<maxdist;
}