// #include<bits/stdc++.h>
// using namespace std;

// void dfs(int node, vector<vector<int>>& adjlist, vector<vector<int>>& ancestor, int parent, vector<int>& depth){
//     ancestor[node][0] = parent;

//     for(auto neighbour : adjlist[node]){
//         if(neighbour == parent) continue;
//         depth[neighbour] = depth[node] + 1;
//         dfs(neighbour, adjlist, ancestor, node, depth);
//     }
// }

// void processes(vector<vector<int>>& adjlist, vector<vector<int>>& ancestor, int N, int maxN, vector<int>& depth){

//     depth[1]= 0;
//     dfs(1, adjlist, ancestor, -1, depth);
//     for(int j=1; j<maxN; j++){
//         for(int i=1; i<=N; i++){
//             if(ancestor[i][j-1] != -1){
//                 ancestor[i][j] = ancestor[ancestor[i][j-1]][j-1];
//             }
//         }
//     }
// }

// int ancestorkthlevel(int node, int k, vector<vector<int>>& ancestor, int maxN){
//     for(int i=maxN; i>=0; i--){
//         if(k & (1 << i)){
//             if(ancestor[node][i] == -1){
//                 return -1;
//             }
//             else node = ancestor[node][i];
//         }
//     }
//     return node;
// }

// int lca(int u, int v, vector<vector<int>>& ancestor, int maxN, vector<int>& depth){
//     if(depth[u] < depth[v]) swap(u, v);

//     int diff = depth[u] - depth[v];
//     u = ancestorkthlevel(u, diff, ancestor, maxN);

//     if(u == v) return u;

//     for(int i=maxN-1; i>=0; i--){
//         if(ancestor[u][i] != ancestor[v][i]){
//             u = ancestor[u][i];
//             v = ancestor[v][i];
//         }
//     }
//     return ancestor[u][0];
// }

// int main(){
//     int n, q;
//     cin>>n>>q;

//     int maxN = log2(n)+1;
//     vector<vector<int>> ancestor(n+1, vector<int>(maxN, -1));
//     vector<int> depth(n+1, 0);
    
//     vector<vector<int>> adjlist (n+1);
//     for(int i=1; i<n; i++){
//         int u, v;
//         cin>>u>>v;
//         adjlist[u].push_back(v);
//         adjlist[v].push_back(u);
//     }

//     processes(adjlist, ancestor, n, maxN, depth);

//     while(q--){
//         int u, v;
//         cin>>u>>v;

//         int L = lca(u, v, ancestor, maxN, depth);
//         int answer = depth[u] + depth[v] - 2*depth[L];

//         cout<<answer<<endl;
//     }

// }


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

    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth[1] = 0;
    dfs(1, -1);

    while(q--){
        int a, b;
        cin >> a >> b;

        int L = lca(a, b);
        int ans = depth[a] + depth[b] - 2 * depth[L];
        cout << ans << '\n';
    }
}
