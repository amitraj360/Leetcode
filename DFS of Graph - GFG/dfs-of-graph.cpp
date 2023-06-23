//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    
    void dfs(int v, vector<int>adj[], int i, vector<int>&ans, vector<int>&visited)
    {
        if(i==v)
        {
            return;
        }
        visited[i]=1;
        ans.push_back(i);
        for(auto j:adj[i])
        {
            if(visited[j]==0)
            {
                dfs(v,adj,j,ans,visited);
            }
        }
        return;
    }
    

    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code
        
        vector<int>visited(V,0);
        vector<int>ans;
        for(int i=0;i<V;i++)
        {
            if(visited[i]==0)
            {
                dfs(V,adj,i,ans,visited);
            }
        }
        return ans;
        
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends