void permuteString(string &s, int idx, vector<string> &ans)
{
    if(idx == s.size()) {
        ans.push_back(s);
        return;
    }
    for(int i=idx; i<s.size(); i++) {
        swap(s[i], s[idx]);
        permuteString(s, idx+1, ans);
        swap(s[i], s[idx]);
    }
    return;
}

vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string> ans;
    permuteString(s, 0, ans);
    return ans;
}
