#include<bits/stdc++.h>

bool compare(pair<int, int> p1, pair<int, int> p2) {
    double v1 = (double) p1.second / (double) p1.first;
    double v2 = (double) p2.second / (double) p2.first;
    return v1 > v2;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(), items.end(), compare);
    double ans = 0;
    for(int i=0; i<n; i++) {
        if(w >= items[i].first){
            ans += items[i].second;
            w -= items[i].first;
            continue;
        }
        double pw = (double) items[i].second / (double) items[i].first;
        ans += pw * w;
        w = 0;
        break;
    }
    return ans;
}
