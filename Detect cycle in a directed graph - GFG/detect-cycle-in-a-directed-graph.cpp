//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool p=false;
    bool cycle(vector<int> adj[], int visited[], int lv[], int node)
    {
        
       // cout<<node<<endl;
        lv[node]=1;
        visited[node]=1;
        for(auto i:adj[node])
        {
           // cout<<"i"<<i<<visited[i]<<lv[i]<<endl;
            if(i==node) return true;
            else if(lv[i]==1 && visited[i]==1)
            {
              //  cout<<"hello"<<node<<endl;
                return true;
            }
            else if(visited[i]==0)
            {
                //cout<<"sdsf";
                p= cycle(adj,visited, lv,i);
            }
            
            
        }
        lv[node]=0;
        return p;
    }
    
    
    
    
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int visited[V]={0};
        int lv[V]={0};
        for(int i=0;i<V;i++)
        {
            if(visited[i]==0)
            {
               /// cout<<"A"<<endl;
                bool t=cycle(adj,visited, lv,i);
                if(t==true) return true;
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