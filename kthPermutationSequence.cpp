#include<bits/stdc++.h>
void permuteString(string &s, int idx, vector<string> &ans)
{
    if(idx >= s.size()) {
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

string kthPermutation(int n, int k) {
    // Write your code here.
    vector<string> ans;
    string s = "";
    for(char i='1'; i<'1'+n; i++) 
        s += i;
    permuteString(s, 0, ans);
    sort(ans.begin(), ans.end());
    return ans[k-1];
}
