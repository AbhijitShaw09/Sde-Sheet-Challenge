#include <bits/stdc++.h> 
string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
    string ans = "No";
    sort(arr.begin(), arr.end());
        for(int i=0;i<n-3;i++) {
            if(i > 0 && arr[i] == arr[i-1]) continue;
            if(arr[i] + arr[i+1] + arr[i+2] + arr[i+3] > target) break;
            if(arr[i] + arr[n-3] + arr[n-2] + arr[n-1] < target) continue;
            for(int j=i+1;j<n-2;j++) {
                if(j > i+1 && arr[j] == arr[j-1]) continue;
                if(arr[i] + arr[j] + arr[j+1] + arr[j+2] > target) break;
                if(arr[i] + arr[j] + arr[n-2] + arr[n-1] < target) continue;
                int left = j+1,right = n-1;
                while(left < right){
                    int sum = arr[left] + arr[right] + arr[i] + arr[j];
                    if(sum < target) left++;
                    else if(sum > target) right--;
                    else{
                        ans = "Yes";
                        return ans;
                    }
                }
            }
        }
        return ans;
}
