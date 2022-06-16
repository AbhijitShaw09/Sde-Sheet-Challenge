int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int zerocnt = 0, i = 0, ans = 0;
    for(int j=0; j<n; j++){
        if(arr[j] == 0)
            zerocnt++;
        while(zerocnt > k){
            if(arr[i] == 0)
                zerocnt--;
            i++;
        }
        ans = max(ans, j-i+1);
    }
    return ans;
}
