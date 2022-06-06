#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
	// Write your code here.
    int count = 0, ele = -1;
    for(int i=0; i<n; i++) {
        if(count == 0)
            ele = arr[i];
        if(arr[i] == ele)
            count++;
        else
            count--;
    }
    count = 0;
    for(int i=0; i<n; i++)
        if(arr[i] == ele)
            count++;
    if(count <= n/2) 
        return -1;
    return ele;
}
