#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(1);
vector<int> colour;

bool dfs(int node, int color){
    colour[node] = color;

    for(auto neighbour : adj[node]){
        if(colour[neighbour] == -1){
            if(!dfs(neighbour, !color)){
                return false;
            }
        }
        else if(colour[neighbour] == color){
            return false;
        }
    }
    return true;
}

int main(){
    int n, m;
    cin>>n>>m;

    adj.resize(n+1);
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    colour.assign(n+1, -1);
    for(int i=1; i<=n; i++){
        if(colour[i] == -1){
            if(!dfs(i, 0)){
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }

    for(int i=1; i<=n; i++){
        if(colour[i] == 0){
            cout<<1<<" ";
        }
        else{
            cout<<2<<" ";
        }
    }
    cout<<endl;
    return 0;
}