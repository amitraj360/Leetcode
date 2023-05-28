//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool x=false;
    bool dfs(vector<int>adj[],int visited[],int lv[], int node)
    {
        lv[node]=1;
        visited[node]=1;
        for(auto i:adj[node])
        {
            if(i==node) return true;
            else if(visited[i]==1 && lv[i]==1)
            {
                return true;
            }
            else if(visited[i]==0)
            {
                x=dfs(adj,visited,lv,i);
            }
            
        }
        lv[node]=0;
        return x;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int visited[V]={0};
        int lv[V]={0};
        for(int i=0;i<V;i++)
        {
            if(visited[i]==0)
            {
                bool t=dfs(adj, visited, lv,i);
                if(t)return t;
            }
        }
        return false;
        
        
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends