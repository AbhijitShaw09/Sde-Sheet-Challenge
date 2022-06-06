#include <bits/stdc++.h> 

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    int r = 0, c = 0, prev;
    while(r < n && c < m) {
        if(r == n-1 || c == m-1)
            return;
        prev = mat[r+1][c];
        for(int i = c; i < m; i++)
            swap(mat[r][i], prev);
        r++;
        for(int i = r; i < n; i++)
            swap(mat[i][m-1], prev);
        m--;
        if(r < n)
            for (int i = m-1; i >= c; i--)
                swap(mat[n-1][i], prev);
        n--;
        if (c < m)
            for (int i = n-1; i >= r; i--)
                swap(mat[i][c], prev);
        c++;
    }
}
