int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
    int i = 0, j = 0;
    for(int i=0; i<n-1; i++) {
        if(arr[i] != arr[i+1])
            arr[j++] = arr[i];
    }
    arr[j++] = arr[n-1];
    return j;
}
