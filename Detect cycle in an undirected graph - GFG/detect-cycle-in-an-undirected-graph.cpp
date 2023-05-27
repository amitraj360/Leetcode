//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:

    bool t=false;
    bool dfs(vector<int>&x,vector<int> adj[],int i,int p)
    {
       // cout<<i<<p<<endl;
        if(x[i]!=0)
            return true;
        
        x[i]=1;
        for(auto j:adj[i])
        {
           // cout<<j<<x[j]<<endl;
            if(j==p) continue;
           // cout<<j<<x[j]<<endl;
            if(j==i ||x[j]==1)
            {
                return true;
            }
                        //cout<<j<<x[j]<<endl;

            if(x[j]==0)
            {
               // cout<<"hello"<<endl;
                t= dfs(x,adj,j,i);
            }
        }
        return t;
    }
    
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
         vector<int>x(V,0);
         
         for(int i=0;i<V;i++)
         {
             if(x[i]==0)
             {
                 bool p=dfs(x,adj,i,-1);
                // cout<<p<<endl;
                 if(p==true)
                 return true;
             }
         }
         return false;
        
    }
};
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
