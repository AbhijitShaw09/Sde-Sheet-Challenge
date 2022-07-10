#include <bits/stdc++.h>

vector<int> generateLPS(string ns) {
    int n = ns.size();
    vector<int> lps(n, 0);
    for(int i = 1; i < n; i++) {
        int len = lps[i - 1];
        
        while(len > 0 && ns[i] != ns[len]) len = lps[len - 1];
        
        if(ns[i] == ns[len]) len++;
        
        lps[i] = len;
    }
    
    return lps;
}
int minCharsforPalindrome(string str) {
	// Write your code here.
	string rev = str;
    reverse(rev.begin(), rev.end());
    
    string ns = str + '$' + rev;
    
    auto lps = generateLPS(ns);
    
    return str.size() - lps.back();
}
