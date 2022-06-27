#include<bits/stdc++.h>
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    vector<int> ans;
    stack<pair<int, int>> s;
    for(auto ele : price) {
        int days = 1;
        while(!s.empty() && s.top().first <= ele){
            days += s.top().second;
            s.pop();
        }
        s.push({ele, days});
        ans.push_back(days);
    }
    return ans;
}
