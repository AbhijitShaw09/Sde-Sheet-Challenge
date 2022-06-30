#include<bits/stdc++.h>
bool isvalid(vector<int> time, int m, int n, long long mx)
{
    long long student= 1;
    long long sum = 0;
    for (long long i = 0; i < m; i++) {
        sum = sum + time[i];
        if(sum > mx){
            student++;
            sum = time[i];
        }
        if(student > n)
            return false;
    }
    return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
    if(m < n)
        return -1;

    long long start = *max_element(time.begin(), time.end());
    long long end = 0;
    end = accumulate(time.begin(), time.end(), end);
    long long res = -1;

    while(start <= end) {
        long long mid = start + ((end - start) / 2);
        if(isvalid(time, m, n, mid)) {
            res = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return res;
}
