#include <bits/stdc++.h>
void findTopoSort(int node, vector<int> &vis, stack<int> &st, unordered_map<int, list<int>> &adj) {
    vis[node] = 1;
    for(auto it : adj[node]) {
        if(!vis[it])
            findTopoSort(it, vis, st, adj);
    }
    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int V, int e)  {
    // Write your code here
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    stack<int> st;
    vector<int> vis(V, 0);
    for(int i=0; i<V; i++)
        if(vis[i] == 0)
            findTopoSort(i, vis, st, adj);
    vector<int> topo;
    while(!st.empty()) {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}
