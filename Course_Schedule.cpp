#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(1);
vector<bool> visited(1);
vector<bool> dfsvisited(1);
stack<int> st;
bool iscyclic = false;

void dfs(int node){
    if(iscyclic) return;

    visited[node] = true;
    dfsvisited[node] = true;

    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            dfs(neighbour);
        }
        else if(dfsvisited[neighbour]){
            iscyclic = true;
            break;
        }
    }

    dfsvisited[node] = false;
    st.push(node);
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
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            dfs(i);
        }
        if(iscyclic){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    return 0;
}

