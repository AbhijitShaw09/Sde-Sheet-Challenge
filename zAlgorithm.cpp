#include<bits/stdc++.h>
vector<int> Making_Z_Table(string s) {
    int n = s.size();
    vector<int> pi(n, 0);
    for(int i=1; i<n; i++) {
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j])
            j = pi[j-1];

        if(s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi; 
 }
int zAlgorithm(string s, string p, int n, int m)
{
	// Write your code here
    string total = p + "$" + s;
    vector<int> z_table = Making_Z_Table(total);    
    vector<int> ans;
    
    for(int i = 0; i < z_table.size(); i++) {
        if(z_table[i] == p.length()) {
            int remove_relative = i - p.length() - 1;
            ans.push_back(remove_relative);
        }
    }
    
    return (int)ans.size();
}
