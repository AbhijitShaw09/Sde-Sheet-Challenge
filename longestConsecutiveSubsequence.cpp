#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    if(n == 0)
        return 0;
    int len = 0, res = INT_MIN;
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++)
       mp[arr[i]]++;

    for(auto i : arr) {
        if(mp.find(i - 1) == mp.end()) {
            int curNum = i;
            int curlen = 1;
            while(mp.find(curNum + 1) != mp.end()) {
                curNum++;
                curlen++;
            }
            res = max(res, curlen);
        }
    }
    return res > 0 ? res : 1;
}
