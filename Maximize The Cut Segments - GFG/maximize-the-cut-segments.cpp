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
        vector<int>dp(n+1,-1);
        int t= soln(n,x,y,z,dp);
        if(t<0)
        {
            return 0;
        }
        return t;
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