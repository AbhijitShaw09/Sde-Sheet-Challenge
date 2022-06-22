#include<bits/stdc++.h>
#define pii pair<int, int>

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    unordered_map<int, int> mp;
    priority_queue<pii , vector<pii>, greater<pii>> minh;
    vector<int> ans;

    for(int i=0; i<n; i++)
        mp[arr[i]]++;
    
    for(auto i=mp.begin(); i!=mp.end(); i++) {
        minh.push({i->second, i->first});
        if(minh.size() > k)
            minh.pop();
    }

    while(minh.size()) {
        ans.push_back(minh.top().second);
        minh.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
}
