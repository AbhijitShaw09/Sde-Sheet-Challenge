#include<bits/stdc++.h>
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    //    Write your code here.
    vector<int> ans;
    if(k > nums.size()) {
        ans.push_back(*max_element(nums.begin(), nums.end())+1);
        return ans;
    }
    int i=0, j=0;
    list<int> l;
    while(j < nums.size()) {
        if(l.empty())
            l.push_back(nums[j]);
        else {
            while(!l.empty() && l.back() < nums[j])
                l.pop_back();
            l.push_back(nums[j]);
        }
        if(j-i+1 < k)
            ++j;
        else if(j-i+1 == k) {
            ans.push_back(l.front());
            if(nums[i] == l.front())
                l.pop_front();
            ++i;
            ++j;
        }
    }
    return ans;
}
