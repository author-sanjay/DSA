//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
  bool isCyclic(int u,int parent,vector<int>adj[],vector<bool>&vis)
  {
      vis[u]=true;
      
      for(int v: adj[u])
      {
          if(vis[v]==false)
          {
              if(isCyclic(v,u,adj,vis))
                return true;
          }
          else if(v!=parent)
          {
              return true;
          }
      }
      return false;
  }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) 
    {
        vector<bool>vis(V,false);
        
        for(int i=0;i<V;i++)
        {
            if(vis[i]==false)
            {
                if(isCyclic(i,-1,adj,vis))
                    return true;
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
