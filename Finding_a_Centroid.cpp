#include <bits/stdc++.h>
using namespace std;

// -------- DFS #1: compute subtree size of every node --------
void dfs(int u, int parent, vector<int>& sub, vector<vector<int>>& adj) {
    sub[u] = 1; // include current node

    for(int v : adj[u]) {
        if(v == parent) continue;

        dfs(v, u, sub, adj);

        sub[u] += sub[v]; // add child subtree size
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n+1);
    vector<int> sub(n+1); 

    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0, sub, adj);

    int centroid = 1;

    // -------- Check each node to see if it's a centroid --------
    for(int u = 1; u <= n; u++) {

        // largest component size when removing u
        int largest_part = n - sub[u]; 
        // (i.e., nodes outside u's subtree)

        for(int v : adj[u]) {
            // if child subtree belongs to u
            if(sub[v] < sub[u] && sub[v] > largest_part)
                largest_part = sub[v];
        }

        // centroid condition: every component ≤ n/2
        if(largest_part <= n / 2) {
            centroid = u;
            break;
        }
    }

    cout << centroid << endl;
    return 0;
}
