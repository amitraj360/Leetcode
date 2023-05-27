//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    
    
    
    
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>x(V,0);
        queue<int>q;
        
        
        
        for(int j=0;j<V;j++)
        {
            if(x[j]!=0)continue;
            q.push(j);
            x[j]=1;
            while(!q.empty())
            {
                int a=q.front();
                x[a]=2;
                q.pop();
                for(auto i:adj[a])
                {
                    if(x[i]==1 || i==a)
                    {
                        return true;
                    }
                    if(x[i]==2)
                    {
                        continue;
                    }
                    if(x[i]==0)
                    {
                        x[i]=1;
                        q.push(i);
                    }
                    
                    
                }
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