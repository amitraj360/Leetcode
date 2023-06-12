//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int soln(int w, int wt[], int val[], int index,vector<vector<int>>&dp)
    {
        if(index==0)
        {
            if(wt[index]<=w)
            return val[0];
            else 
            return 0;
        }
        if(dp[w][index]!=-1)
        {
            return dp[w][index];
        }
        int a=0;
        if(w>=wt[index])
        {
            a=val[index]+soln(w-wt[index],wt,val,index-1,dp);
        }
        int b=0+soln(w,wt,val,index-1,dp);
        
        dp[w][index]= max(a,b);
        
        return dp[w][index];
    }
    
    
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(W+1,vector<int>(n+1,-1));
       return soln(W,wt, val,n-1,dp);
       
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends