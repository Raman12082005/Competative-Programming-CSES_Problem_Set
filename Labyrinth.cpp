#include<bits/stdc++.h>
using namespace std;
int main(){
    int rows, cols;
    cin>>rows>>cols;

    vector<vector<char>> grid(rows, vector<char>(cols));
    pair<int, int> start, end;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cin>>grid[i][j];
            if(grid[i][j] == 'A') start = {i, j};
            if(grid[i][j] == 'B') end = {i, j};
        }
    }
    
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<vector<char>> parent(rows, vector<char>(cols, '?'));

    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    vector<char> dir = {'D', 'U', 'R', 'L'};

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(make_pair(x, y) == end) break;

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx>=0 && ny>=0 && nx<rows && ny<cols){
                if(!visited[nx][ny] && grid[nx][ny] != '#'){
                    visited[nx][ny] = true;
                    parent[nx][ny] = dir[i];
                    q.push({nx, ny});
                }
            }
        }
    }

    if(!visited[end.first][end.second]){
        cout<<"NO"<<endl;
        return 0;
    }

    cout<<"YES"<<endl;

    string path = "";
    pair<int, int> curr = end;
    while(curr != start){
        char p = parent[curr.first][curr.second];
        path.push_back(p);

        if(p == 'U') curr.first += 1;
        else if(p == 'D') curr.first -= 1;
        else if(p == 'L') curr.second += 1;
        else if(p == 'R') curr.second -= 1;
    }
    reverse(path.begin(), path.end());
    cout<<path.size()<<endl;
    cout<<path<<endl;
}