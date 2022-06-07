#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	pair<int, int> ans;
    long long int len = arr.size(), s1 = 0, s2 = 0, missing = 0, repeating = 0;

    s1 = (len * (len+1) ) /2;
    s2 = (len * (len +1) *(2*len +1) )/6;
     
    for(int i=0;i<len; i++){
       s1 -= (long long int)arr[i];
       s2 -= (long long int)arr[i]*(long long int)arr[i];
    }
     
    missing = (s1 + s2/s1)/2;

    repeating = missing - s1;
    ans.first = missing;
    ans.second = repeating;
    return ans;
}
