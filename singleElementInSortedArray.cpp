int uniqueElement(vector<int> arr, int n)
{
	// Write your code here
    int low = 0, high = arr.size()-1;
    while(low < high) {
        int mid = low + ((high - low) / 2);

        if((mid % 2 == 0 && arr[mid] == arr[mid + 1]) || ((mid % 2 == 1 && arr[mid] == arr[mid - 1])))
            low = mid + 1;
        else
            high = mid;
    }
    return arr[low];
}
