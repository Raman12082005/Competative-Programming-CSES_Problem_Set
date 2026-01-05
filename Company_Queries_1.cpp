// Algo used - Binary Lifting 
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000;
const int LOG = 20; // because 2^20 > 2 * 10^5

// up[x][j] = boss of employee x at 2^j levels above
int up[MAXN+1][LOG];

int main(){

    int n, q;
    cin>>n>>q;

    // Employee 1 is the general director (no boss)
    up[1][0] = -1;

    // Read direct bosses
    for(int i = 2; i <= n; i++){
        cin >> up[i][0];
    }

    // Precompute the jump table
    for(int j = 1; j < LOG; j++){
        for(int i = 1; i <= n; i++){
            if(up[i][j - 1] == -1){
                up[i][j] = -1;
            }
            else{
                up[i][j] = up[up[i][j-1]][j-1];
            }
        }
    }

    // Process queries
    while(q--){
        int x, k;
        cin >> x >> k;

        // Move x upwards according to binary representation of k
        for(int j = 0; j < LOG; j++){
            if(k & (1 << j)){
                x = up[x][j];
                if(x == -1){
                    break;
                }
            }
        }
        cout<<x<<endl;
    }
}




