#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    vector<int> mp(256, -1);
    int left = 0, right = 0, n = input.size(), len = 0;
    while(right < n) {
        if(mp[input[right]] != -1)
            left = max(mp[input[right]] + 1, left);
        mp[input[right]] = right;
        len = max(len, right - left + 1);
        right++;
    }
    return len;
}
