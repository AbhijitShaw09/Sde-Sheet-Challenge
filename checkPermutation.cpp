#include<bits/stdc++.h>
bool areAnagram(string &str1, string &str2){
    // Write your code here.
    if(str1.size() != str2.size())
        return false;
    
    if(str1 == str2)
        return true;
    
    unordered_map<char, int> helper;
    for(int i=0; i<str1.size(); i++)
        helper[str1[i]]++;
    
    for(int i=0; i<str2.size(); i++)
        if(helper.find(str2[i]) == helper.end())
            return false;
    
    return true;
}
