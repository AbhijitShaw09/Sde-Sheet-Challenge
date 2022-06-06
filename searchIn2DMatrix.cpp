#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    // Write your code here.
    int low = 0, high = m*n-1;
    while(low <= high) {
        int mid = low + ((high-low)/2);
        if(target == mat[mid/n][mid%n])
            return true;
        else if (target > mat[mid/n][mid%n])
            low = mid+1;
        else
            high = mid-1;
    }
    return false;
}
