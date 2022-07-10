#include<bits/stdc++.h>
int p = 31;
const int N = 1e5+7, m = 1e9+7;
vector<long long> power(N);

vector<int> stringMatch(string &str, string &pat) {
    // Write your code here
    transform(pat.begin(), pat.end(), pat.begin(), ::tolower);
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    int ts = str.size(), ps = pat.size();

    power[0] = 1;
    for(int i=1; i<N; i++) {
        power[i] = (power[i-1] * p) % m;
    }

    vector<long long> h(ts+1, 0);
    for(int i=0; i<ts; i++) {
        h[i+1] = (h[i] + (str[i] - 'a' + 1) * power[i]) % m;
    }

    long long h_s = 0;
    for(int i=0; i<ps; i++) {
        h_s = (h_s + (pat[i] - 'a' + 1) * power[i]) % m;
    }

    vector<int> ans;
    for(int i = 0; i+ps-1 < ts; i++) {
        long long cur_h = (h[i+ps] - h[i] + m) % m;
        if(cur_h == (h_s * power[i]) % m) {
            ans.push_back(i);
        }
    }
    return ans;
}
