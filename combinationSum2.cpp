#include <bits/stdc++.h>

void subsequence(int idx, int target, vector<int>& arr, vector<int>& v, vector<vector<int>>& ans){
    if(target == 0){
        ans.push_back(v);
        return ;
    }
    for(int i=idx; i<arr.size(); i++) {
        if(i>idx && arr[i]==arr[i-1])
            continue;
        if(arr[i]>target)
            break;
        v.push_back(arr[i]);
        subsequence(i+1, target-arr[i], arr, v, ans);
        v.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> v;
    subsequence(0, target, arr, v, ans);
    return ans;
}
