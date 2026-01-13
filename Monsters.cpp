#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>> Monster_dist(n, vector<int>(m, INT_MAX));
    vector<vector<int>> Player_dist(n, vector<int>(m, INT_MAX));
    queue<pair<int, int>> mq;
    queue<pair<int, int>> pq;
    int start_i = -1, start_j = -1;

    vector<vector<char>> grid(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
            
            // if player found
            if(grid[i][j] == 'A'){
                start_i = i;
                start_j = j;
                pq.push({i, j});
                Player_dist[i][j] = 0;
            }

            // if Monster found
            else if(grid[i][j] == 'M'){
                mq.push({i, j});
                Monster_dist[i][j] = 0;
            }
        }
    }

    vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<char> dirch = {'D', 'R', 'U', 'L'};

    while(!mq.empty()){
        int x = mq.front().first;
        int y = mq.front().second;
        mq.pop();


        for(int i=0; i<4; i++){
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;

            if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
            if(grid[nx][ny] == '#') continue;

            if(Monster_dist[nx][ny] > Monster_dist[x][y] + 1){
                Monster_dist[nx][ny] = Monster_dist[x][y] + 1;
                mq.push({nx, ny});
            }
        }
    }

    vector<vector<char>> Player_dir(n, vector<char>(m));
    while(!pq.empty()){
        int x = pq.front().first;
        int y = pq.front().second;
        pq.pop();

        // check if palyer reach outside the grid
        if(x==0 || y==0 || x==n-1 || y==m-1){
            cout<<"YES"<<endl;

            // construct path
            string path = "";
            while(!(x == start_i && y == start_j)){
                char ch = Player_dir[x][y];
                path.push_back(ch);

                // move in reverse direction
                if(ch == 'U') x += 1;
                else if(ch == 'D') x -= 1;
                else if(ch == 'L') y += 1;
                else if(ch == 'R') y -= 1;
            }

            reverse(path.begin(), path.end());
            cout<<path.size()<<endl;
            cout<<path<<endl;
            return 0;
        }

        for(int i=0; i<4; i++){
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;

            if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
            if(grid[nx][ny] == '#') continue;

            int next_dist = Player_dist[x][y] + 1;

            if(next_dist >= Monster_dist[nx][ny]) continue;

            if(next_dist < Player_dist[nx][ny]){
                Player_dist[nx][ny] = next_dist;
                pq.push({nx, ny});
                Player_dir[nx][ny] = dirch[i];
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}






