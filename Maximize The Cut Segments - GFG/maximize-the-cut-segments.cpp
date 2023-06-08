//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    
    
    int soln(int n, int x, int y, int z,vector<int>&dp)
    {
        if(n==0)
        {
            return 0;
        }
        if(n<0)
        {
            return INT_MIN;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int a=soln(n-x,x,y,z,dp);
        int b=soln(n-y,x,y,z,dp);
        int c=soln(n-z,x,y,z,dp);
        dp[n]=max({a+1,b+1,c+1});
        return dp[n];
    }
    
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int>dp(n+1,INT_MIN);
        
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            int a,b,c;
            a=b=c=INT_MIN;
            if(i-x>=0 && dp[i-x]!=INT_MIN)
            {
                a=1+dp[i-x];
            }
            if(i-y>=0 && dp[i-y]!=INT_MIN)
            {
                b=1+dp[i-y];
            }
            if(i-z>=0 && dp[i-z]!=INT_MIN)
            {
                c=1+dp[i-z];
            }
            dp[i]=max({a,b,c});
            
        }
        
        // int t= soln(n,x,y,z,dp);
        if(dp[n]<0)
        {
            return 0;
        }
        return dp[n];
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends