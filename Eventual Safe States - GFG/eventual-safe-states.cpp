//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  
  
    bool dfs(int node, vector<int>adj[], vector<int>&visited, vector<int>&track)
    {
        if(track[node]!=-1)return track[node];
        visited[node]=1;
        bool a=true;
        for(auto i:adj[node])
        {
            if(visited[i]==1)
            
                return track[node]=false;
            else
                a=a && dfs(i,adj,visited,track);

        }
        visited[node]=0;
        return track[node]=a;
    }
  
  
  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int>track(V+1,-1);
        vector<int>ans;
        for(int i=0;i<V;i++)
        {
            vector<int>visited(V,0);
            bool a=dfs(i,adj,visited,track);
            if(a) ans.push_back(i);
        }
        return ans;
        
        
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends