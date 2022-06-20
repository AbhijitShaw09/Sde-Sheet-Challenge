vector<vector<int>> ans;
#include<bits/stdc++.h>
bool is_valid(vector<vector<int>> &board, int row, int col, int n) {
    for(int i=0; i<row; i++)
        if(board[i][col])
            return false;
    int i = row-1, j = col-1;
    while(i >= 0 && j >= 0) {
       if(board[i][j])
           return false;
       i--; j--;
    }
    i = row-1, j = col+1;
    while(i >= 0 && j < n) {
       if(board[i][j])
           return false;
       i--; j++;
    }
    return true;
}
void dfs(vector<vector<int>> &board, int row, int n, int q) {
    if(row == n && q == n) {
       vector<int> v;
       for(auto a : board)
           for(int b : a)
               v.push_back(b);
       ans.push_back(v);
       return;
   }
    for(int i=0; i<n; ++i) {
        if(is_valid(board, row, i, n)) {
            board[row][i] = 1;
            dfs(board, row+1, n, q+1);
            board[row][i] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    if(n <= 0) return {{}};
    vector<vector<int>> board(n, vector<int>(n, 0));
    dfs(board, 0, n, 0);
    return ans;
}
