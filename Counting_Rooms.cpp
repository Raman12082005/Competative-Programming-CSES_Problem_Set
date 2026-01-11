#include<bits/stdc++.h>
using namespace std;
void helper(int i, int j, vector<vector<char>>& grid){
    // base cases
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == '#'){
        return;
    }

    grid[i][j] = '#';

    helper(i+1, j, grid);
    helper(i-1, j, grid);
    helper(i, j+1, grid);
    helper(i, j-1, grid);
}
int main(){
    int rows, cols;
    cin>>rows>>cols;

    vector<vector<char>> grid(rows, vector<char>(cols));
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cin>>grid[i][j];
        }
    }

    int rooms = 0;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
           if(grid[i][j] == '.'){
                rooms++;
                helper(i, j, grid);
           }
        }
    }
    cout<<rooms<<endl;
}