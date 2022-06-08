#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int cnt = 0, xorr = 0;
    map<int, int> mp;
    for(int i=0; i<arr.size(); i++) {
        xorr ^= arr[i];
        if(xorr == x)
            cnt++;
        if(mp.find(xorr ^ x) != mp.end())
            cnt += mp[xorr ^ x];
        mp[xorr] += 1;
    }
    return cnt;
}
