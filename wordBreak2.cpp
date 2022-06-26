void words(string &s, int start, vector<string> &dictionary, vector<string> &ans, string &curr) {
    if(start >= s.size()) {
        ans.push_back(curr);
        return;
    }
    
    for(int i=start; i<s.size(); i++) {
        string t = s.substr(start, i-start+1);
        
        bool isPresent = false;
        for(string st: dictionary) {
            if(st.compare(t) == 0) {
                isPresent = true;
                break;
            }
        }
        
        if(isPresent) {
            string x = curr;
            curr += t + " ";
            words(s, i+1, dictionary, ans, curr);
            curr = x;
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    vector<string> ans;
    string curr;
    
    words(s, 0, dictionary, ans, curr);
    
    return ans;
}
