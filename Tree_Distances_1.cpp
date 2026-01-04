#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adjlist;
vector<int> dist;

void dfs(int node, int parent, int depth){
    dist[node] = depth;

    for(auto neighbour : adjlist[node]){
        if(neighbour != parent){
            dfs(neighbour, node, depth+1);
        }
    }
}
int main(){
    int n;
    cin>>n;

    adjlist.resize(n+1);

    for(int i=0; i<n-1; i++){
        int u, v;
        cin>>u>>v;

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    // try to find one end of the diameter which is A
    dist.assign(n+1, 0);
    dfs(1, -1, 0);

    int A = 1;
    for(int i=1; i<=n; i++){
        if(dist[i] > dist[A]){
            A = i;
        }
    }

    // try to find other end of the diameter which is B
    dist.assign(n+1, 0);
    dfs(A, -1, 0);
    vector<int> distA = dist; // maxdist of each node from end A

    int B = A;
    for(int i=1; i<=n; i++){
        if(dist[i] > dist[B]){
            B = i;
        }
    }

    dist.assign(n+1, 0);
    dfs(B, -1, 0);
    vector<int> distB = dist; // maxdist of each node from end B

    for(int i=1; i<=n; i++){
        cout<<max(distA[i], distB[i])<<" ";
    }
}
