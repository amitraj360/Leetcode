//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    // int soln(int w, int wt[], int val[], int index,vector<vector<int>>&dp)
    // {
    //     if(index==0)
    //     {
    //         if(wt[index]<=w)
    //         return val[0];
    //         else 
    //         return 0;
    //     }
    //     if(dp[w][index]!=-1)
    //     {
    //         return dp[w][index];
    //     }
    //     int a=0;
    //     if(w>=wt[index])
    //     {
    //         a=val[index]+soln(w-wt[index],wt,val,index-1,dp);
    //     }
    //     int b=0+soln(w,wt,val,index-1,dp);
        
    //     dp[w][index]= max(a,b);
        
    //     return dp[w][index];
    // }
    
    
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(W+1,vector<int>(n+1,0));
       for(int i=wt[0];i<=W;i++)
       {
           if(wt[0]<=i)
           {
               dp[i][0]=val[0];
           }
           else
           {
               dp[i][0]=0;
           }
       }
       
       for(int i=0;i<n;i++)
       {
           
          for(int j=1;j<=W;j++)
          {
                int a=0;
                if(j>=wt[i])
                {
                    a=val[i]+dp[j-wt[i]][i-1];
                    
                }
                int b=0+dp[j][i-1];
                
                dp[j][i]= max(a,b);
          }
       }
       
       return dp[W][n-1];
       
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