void Subsequence(int idx, int sum, vector<int> &arr, vector<int> &v, vector<vector<int>> &ans) {
    if(idx == arr.size()) {
        if(sum == 0)
            ans.push_back(v);
        return;
    }
    else {
        v.push_back(arr[idx]);
        Subsequence(idx+1, sum-arr[idx], arr, v, ans);
        v.pop_back();
        Subsequence(idx+1, sum, arr, v, ans);
    }
    
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<int> v;
    vector<vector<int>> ans;
    Subsequence(0, k, arr, v, ans);
    return ans;
}
