#include<bits/stdc++.h>
using namespace std;

vector<bool> visited(1);
vector<bool> dfsvisited(1);
vector<int> parent(1);
vector<vector<int>> adj(1);
int start = -1, finish = -1;

bool dfs(int node, int par){
    visited[node] = true;
    dfsvisited[node] = true;
    parent[node] = par;

    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            if(dfs(neighbour, node)){
                return true;
            }
        }
        else if(dfsvisited[neighbour]){
            start = neighbour;
            finish = node;
            return true;
        }
    }
    dfsvisited[node] = false;
    return false;
}

int main(){
    int n, m;
    cin>>n>>m;

    adj.resize(n+1);
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;

        adj[a].push_back(b);
    }

    visited.assign(n+1, false);
    dfsvisited.assign(n+1, false);
    parent.assign(n+1, -1);

    for(int i=1; i<=n; i++){
        if(!visited[i]){
            if(dfs(i, -1)){
                break;
            }
        }
    }

    if(start == -1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    vector<int> result;
    while(finish != start){
        result.push_back(finish);
        finish = parent[finish];
    }
    result.push_back(finish);

    cout<<result.size()+1<<endl;
    for(int i=result.size()-1; i>=0; i--){
        cout<<result[i]<<" ";
    }
    cout<<start<<endl;
    return 0;
}