#include<bits/stdc++.h>
using namespace std;

vector<bool>visited(1);
vector<vector<int>> adj(1);

void dfs(int node){
    visited[node] = true;

    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            dfs(neighbour);
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;

    visited.assign(n+1, false);
    adj.resize(n+1);
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> comp;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            comp.push_back(i);
            dfs(i);
        }
    }

    if(comp.size() == 1){
        cout<<0<<endl;
        return 0;
    }

    // no. of roads needed
    cout<<comp.size()-1<<endl;

    // connect every component to comp[0]
    int firstnode = comp[0];
    for(int i=1; i<comp.size(); i++){
        cout<<firstnode<<" "<<comp[i]<<endl;
    }
    return 0;
}

