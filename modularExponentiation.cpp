#include <bits/stdc++.h> 
int modularExponentiation(int x, int n, int m) {
	// Write your code here.
    long ans = 1;
    long t = x;
    while(n > 0) {
        if(n % 2 == 0) {
            t = (t % m * t % m) % m;
            n = n >> 1;
        } else {
            ans = (ans * t % m) % m;
            n = n - 1;
        }
    }
    return (int)(ans % m);
}
