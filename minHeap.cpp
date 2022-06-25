#include<bits/stdc++.h>

vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    priority_queue<int, vector<int>, greater<int>> minh;
    vector<int> v;
    for(int i=0; i<n; i++) {
        if(q[i].size() == 2)
            minh.push(q[i][1]);
        else {
            v.push_back(minh.top());
            minh.pop();
        }
    }
    return v;
}
