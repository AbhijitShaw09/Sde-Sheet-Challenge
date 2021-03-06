#include <bits/stdc++.h>
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int min = INT_MAX, profit = 0;
    for(int i=0; i<prices.size(); i++) {
        if(prices[i] < min)
            min = prices[i];
        else
            profit = max(profit, prices[i] - min);
    }
    return profit;
}
