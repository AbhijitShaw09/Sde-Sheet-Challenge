#include<bits/stdc++.h>
class Kthlargest {
    priority_queue<int,vector<int>,greater<int>>q;
public:
    Kthlargest(int k, vector<int> &arr) {
       // Write your code here.
        for (int i=0;i<arr.size();i++)
           q.push(arr[i]);
    }

    void add(int num) {
        // Write your code here.
        if (num <= q.top())
            return;
        q.push(num);
        q.pop();
    }

    int getKthLargest() {
       // Write your code here.
        return q.top();
    }

};
