#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.
    long mxl[n], mxr[n], water[n], sum = 0;

    mxl[0] = arr[0];
    for(long i=1; i<n; i++)
        mxl[i] = max(mxl[i-1], arr[i]);

    mxr[n-1] = arr[n-1];
    for(long i=n-2; i>=0; i--)
        mxr[i] = max(mxr[i+1], arr[i]);

    for(long i=0; i<n; i++)
        water[i] = min(mxl[i], mxr[i]) - arr[i];

    for(long i=0; i<n; i++)
        sum += water[i];
    return sum;
}
