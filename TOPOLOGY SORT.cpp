#include <bits/stdc++.h>

void toposort(int i,stack<int> &s,vector<bool> &visited,unordered_map<int,list<int>>adj){
    visited[i]=1;
    for(auto node:adj[i]){
        if(!visited[node]){
            toposort(node,s,visited,adj);
        }
    }
    s.push(i);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int,list<int>> adj;
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        
    }
    
    stack<int> s;
    vector<bool> visited(v);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            toposort(i,s,visited,adj);
        }
    }
    
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
