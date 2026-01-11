#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> visited(n+1);
    vector<int> parent(n+1);
    queue<int> q;
    q.push(1);
    visited[1] = true;
    parent[1] = -1;

    int steps = 0;
    bool found = false;
    while(!q.empty()){
        int size = q.size();
        steps++;
        
        while(size--){
            int curr = q.front();
            q.pop();
            
            // check for answer
            if(curr == n){
                found = true;
                break;
            }

            for(auto neighbour : adj[curr]){
                if(!visited[neighbour]){
                    visited[neighbour] = true;
                    q.push(neighbour);
                    parent[neighbour] = curr;
                }
            }
        }
        if(found) break;
    }
    if(!found){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<steps<<endl;
    vector<int> track;
    track.push_back(n);
    int par = parent[n];
    while(par != 1){
        track.push_back(par);
        par = parent[par];
    }
    track.push_back(par);
    for(int i=track.size()-1; i>=0; i--){
        cout<<track[i]<<" ";
    }
    cout<<endl;
}