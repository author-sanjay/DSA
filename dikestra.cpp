#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    unordered_map<int,list<pair<int,int>>> mp;
    for(int i=0;i<edges;i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];
        
        mp[u].push_back(make_pair(v,w));
        mp[v].push_back(make_pair(u,w));
    }
    
    vector<int> dist(vertices,INT_MAX);

    set<pair<int,int>> st;
    dist[source]=0;
    st.insert(make_pair(0,source));
    
    while(!st.empty()){
        auto top= *(st.begin());
        int nodedist=top.first;
        int topNode=top.second;
        
        st.erase(st.begin());
        
        for(auto i:mp[topNode]){
            if(nodedist+i.second < dist[i.first]){
                auto record=st.find(make_pair(dist[i.first],i.first));
                if(record!=st.end()){
                    st.erase(record);
                }
                dist[i.first]=nodedist+i.second;
                st.insert(make_pair(dist[i.first],i.first));
            }
        }
        
        
    }
    return dist;
}
