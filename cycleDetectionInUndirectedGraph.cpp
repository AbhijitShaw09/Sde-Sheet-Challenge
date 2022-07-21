#include<bits/stdc++.h>
bool checkCycle(int node, int parent, vector<int> &vis, vector<int> adj[]) {
    vis[node] = 1;
    for(auto it: adj[node]) {
        if(vis[it] == 0) {
            if(checkCycle(it, node, vis, adj))
                return true;
        }
        else if(it != parent)
            return true;
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<int> adj[n+1];
    for(int i = 0;i<m;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> vis(n+1,0);
    for(int i =1;i<=n;i++)
        if(!vis[i])
            if(checkCycle(i, -1, vis, adj))
                return "Yes";
    return "No";
}
