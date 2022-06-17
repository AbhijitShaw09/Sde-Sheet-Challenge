#include<bits/stdc++.h>
int knapsack(int arr[], int amount, int n) {
    int mincoins=0;
    for(int i=n-1;i>=0;i--) {
       if(amount/arr[i]>=1) {
           mincoins+=amount/arr[i];
           amount=amount%arr[i];
       }
        if(amount==0) break;
    }
    return mincoins;
}

int findMinimumCoins(int amount) 
{
    // Write your code here
    int coin[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = sizeof(coin) / sizeof(*coin);
    return knapsack(coin, amount, n);
}
