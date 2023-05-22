//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	



	
	
	int minCoins(int coins[], int m, int v) 
	{
	    
	    int dp[v+1];
	    dp[0]=0;
	    for(int i=1;i<=v;i++)
	    {
	        dp[i]=INT_MAX;
	    }
	    
	    for(int i=1;i<=v;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(coins[j]<=i)
	            {
	                int temp=dp[i-coins[j]];
	                if(temp!=INT_MAX && temp+1<dp[i])
	                {
	                    dp[i]=temp+1;
	                }
	                
	            }
	        }
	    }
	    if(dp[v]==INT_MAX)
	    {
	        return -1;
	    }
	    
	        return dp[v];
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends