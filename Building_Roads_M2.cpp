#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> parent, size;
public:
    DisjointSet(int n){
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

        size[ulp_u] += size[ulp_v];
        parent[ulp_v] = ulp_u;
    }
};

int main(){
    int n, m;
    cin>>n>>m;

    DisjointSet ds(n);

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;

        ds.UnionBySize(a, b);
    }

    vector<int> comp;
    for(int i=1; i<=n; i++){
        if(ds.findUpar(i) == i){
            comp.push_back(i);
        }
    }
    // no. of roads needed
    cout<<comp.size()-1<<endl;

    for(int i=1; i<comp.size(); i++){
        cout<<comp[i-1]<<" "<<comp[i]<<endl;
    }
    return 0;
}

