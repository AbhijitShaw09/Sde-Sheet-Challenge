#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	// Write your code here.
    int N = n + m - 2;
    int R = m - 1; 
    double ans = 1;

    for (int i = 1; i <= R; i++)
        ans = ans * (N - R + i) / i;
    return (int)ans;
}
