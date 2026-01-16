#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> parent, size;
public:
    int component;
    DisjointSet(int n){
        component = n;
        parent.resize(n+1);
        size.assign(n+1, 1);

        for(int i=1; i<=n; i++){
            parent[i] = i;
        }
    }
    int findUpar(int node){
        if(parent[node] == node) return node;

        // path compression
        return parent[node] = findUpar(parent[node]);
    }
    void UnionBySize(int u, int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]) swap(ulp_u, ulp_v);

        component--;
        size[ulp_u] += size[ulp_v];
        parent[ulp_v] = ulp_u;
    }
};
int main(){
    int n, m;
    cin>>n>>m;

    vector<pair<pair<long long, int>, int>> adj;
    DisjointSet ds(n);

    while(m--){
        int u, v;
        long long wt;
        cin>>u>>v>>wt;

        adj.push_back({{wt, u}, v});
    }
    sort(adj.begin(), adj.end());
    
    long long mst = 0;
    for(int i=0; i<adj.size(); i++){
        long long wt = adj[i].first.first;
        int u = adj[i].first.second;
        int v = adj[i].second;

        if(ds.findUpar(u) != ds.findUpar(v)){
            mst += wt;
            ds.UnionBySize(u, v);
        }
    }
    if(ds.component != 1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<mst<<endl;
    return 0;
}