void solve(int idx, vector <int>& num, int n, vector <int>& ans, int sum) {
    if (idx == n) {
        ans.push_back(sum);
        return;
    }
    solve(idx + 1, num, n, ans, sum + num[idx]);
    solve(idx + 1, num, n, ans, sum);
}
vector<int> subsetSums(vector<int> num, int n) {
    vector<int> ans;
    solve(0, num, n, ans, 0);
    return ans;
}
vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans = subsetSums(num, num.size());
    sort(ans.begin(), ans.end());
    return ans;
}
