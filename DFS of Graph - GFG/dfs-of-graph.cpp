//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.\\
    
    vector<int>t;
    
    void dfs(vector<int>adj[],unordered_map<int,int>&x,int index)
    {
        
        if(x[index]==1)
        {
            return;
        }
        t.push_back(index);
        x[index]=1;
        for(auto j:adj[index])
        {
            if(x[j]!=1)
            {
                dfs(adj,x,j);
            }
        }
        
    }
    
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        unordered_map<int,int>x;
        for(int i=0;i<V;i++)
        {
            if(x[i]!=1)
            {
                dfs(adj, x,i);
            }
            
        }
        return t;
        
        
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