//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>x;
        vector<int>v(V,-1);
        
        x.push({0,0});
        int sum=0;
        while(!x.empty())
        {
            auto  t=x.top();
            x.pop();
            int a=t.second;
            int w=t.first;
            //cout<<w<<endl;
            if(v[a]==1)
            {
                continue;
            }
            v[a]=1;
            
           // cout<<w<<endl;
            sum+=w;
            for(auto i:adj[a])
            {
                
                int adjnode=i[0];
                int weight=i[1];
                //cout<<weight<<endl;
                //cout<<v[adjnode]<<endl;
                if(v[adjnode]==-1)
                {
                   // cout<<weight<<" "<<adjnode<<endl;
                    x.push({weight,adjnode});
                }
            }
            
        }
        return sum;
        
        
        
        
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends