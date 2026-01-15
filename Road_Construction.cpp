#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> parent, size;
public:
    int maxsize;
    int component;

    DisjointSet(int n){
        parent.resize(n+1);
        size.assign(n+1, 1);
        component = n;
        maxsize = 1;

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
        parent[ulp_v] = ulp_u;
        size[ulp_u] += size[ulp_v];

        component--;
        maxsize = max(maxsize, size[ulp_u]);
    }
};
int main(){
    int n, m;
    cin>>n>>m;

    DisjointSet ds(n);

    int component = n;
    while(m--){
        int a, b;
        cin>>a>>b;

        ds.UnionBySize(a, b);

        cout<<ds.component<<" "<<ds.maxsize<<endl;
    }
    cout<<endl;
    return 0;
}