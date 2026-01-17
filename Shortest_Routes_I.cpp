#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;

    vector<long long> dist (n+1, LLONG_MAX);
    vector<vector<pair<int, long long>>> adj(n+1); // u -> {v, wt}
    set<pair<long long, int>> st; // {dist, node}

    dist[1] = 0;
    while(m--){
        int u, v;
        long long wt;
        cin>>u>>v>>wt;

        adj[u].push_back({v, wt});
    }
    
    st.insert({0, 1});
    while(!st.empty()){
        auto front = *st.begin();
        int currnode = front.second;
        long long dist_currnode = front.first;

        st.erase(st.begin());

        for(auto neighbour : adj[currnode]){
            if(neighbour.second + dist[currnode] < dist[neighbour.first]){

                auto record = st.find({dist[neighbour.first], neighbour.first});
                if(record != st.end()){
                    st.erase(record);
                }

                // update dist
                dist[neighbour.first] = dist_currnode + neighbour.second;
                st.insert({dist[neighbour.first], neighbour.first});
            }
        }
    }

    for(int i=1; i<=n; i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    return 0;
}