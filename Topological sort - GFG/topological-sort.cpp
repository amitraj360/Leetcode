//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	void calc(vector<int>adj[],int n,vector<int>&ind)
	{
	    for(int i=0;i<n;i++)
	    {
	        for(auto j:adj[i])
	        {
	            ind[j]++;
	        }
	    }
	}
	
	
	
	
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>ind(V,0);
	    calc(adj,V,ind);
	    queue<int>q;
	    vector<int>ans;
	    bool visit[V]={0};
	    for(int i=0;i<V;i++)
	    {
	        if(ind[i]==0)
	        {
	            q.push(i);
	            visit[i]=1;
	            ans.push_back(i);
	        }
	    }
	    while(!q.empty())
	    {
	        int t=q.front();
	        q.pop();
	        for(auto j:adj[t])
	        {
	            ind[j]--;
	            if(ind[j]==0)
	            {
	                q.push(j);
	                ans.push_back(j);
	            }
	        }
	    }
	    
	    return ans;
	 
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends