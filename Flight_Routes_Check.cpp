#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<bool>& visited, stack<int>& st, vector<vector<int>>& adj){
    visited[node] = true;

    for(auto it : adj[node]){
        if(!visited[it]){
            dfs(it, visited, st, adj);
        }
    }
    st.push(node);
}
void dfs3(int node, vector<bool>& visited, vector<vector<int>>& adjT){
    visited[node] = true;

    for(auto it : adjT[node]){
        if(!visited[it]){
            dfs3(it, visited, adjT);
        }
    }
}
int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);
    while(m--){
        int a, b;
        cin>>a>>b;

        adj[a].push_back(b);
    }
    stack<int> st;
    vector<bool> visited(n+1, false);
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            dfs(i, visited, st, adj);
        }
    }

    vector<vector<int>> adjT(n+1);
    for(int i=1; i<=n; i++){
        for(auto it : adj[i]){
            adjT[it].push_back(i);
        }
        visited[i] = false;
    }
    int start = st.top();
    int scc = 0, finish = -1;
    while(!st.empty()){
        int currnode = st.top();
        st.pop();

        if(!visited[currnode]){
            scc++;
            finish = currnode;
            dfs3(currnode, visited, adjT);
        }
    }
    if(scc == 1){
        cout<<"YES"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
    cout<<finish<<" "<<start<<endl;
    return 0;
}