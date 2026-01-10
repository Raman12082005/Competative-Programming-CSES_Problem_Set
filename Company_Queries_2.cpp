#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000; // maximum nodes
const int LOG = 20;

vector<int> adj[MAXN+1];
int up[MAXN+1][LOG];
int depth[MAXN+1];

void dfs(int v, int p){
    up[v][0] = p;
    for(int i = 1; i < LOG; i++){
        if(up[v][i-1] != -1)
            up[v][i] = up[ up[v][i-1] ][i-1];
        else
            up[v][i] = -1;
    }

    for(int to : adj[v]){
        if(to == p) continue;
        depth[to] = depth[v] + 1;
        dfs(to, v);
    }
}

int lca(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);

    int diff = depth[a] - depth[b];
    for(int i = LOG-1; i >= 0; i--){
        if(diff & (1<<i))
            a = up[a][i];
    }

    if(a == b) return a;

    for(int i = LOG-1; i >= 0; i--){
        if(up[a][i] != up[b][i]){
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

int main(){
    int n, q;
    cin >> n >> q;

    for(int i = 2; i <= n; i++){
        int parent;
        cin>>parent;
        adj[i].push_back(parent);
        adj[parent].push_back(i);
    }

    depth[1] = 0;
    dfs(1, -1);

    while(q--){
        int a, b;
        cin >> a >> b;

        int L = lca(a, b);
        cout << L << '\n';
    }
}
