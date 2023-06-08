//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    
    int soln( int arr[], int n, vector<int>&dp)
    {
        if(n<0)
        {
            return 0;
        }
        if(n==0)
        {
            return arr[n];
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int a=soln(arr, n-2,dp)+arr[n];
        int b=soln(arr,n-1,dp);
        dp[n]=max(a,b);
        return dp[n];
    }
    
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        vector<int>dp(n+1,-1);
        dp[0]=arr[0];
        dp[1]=max(arr[0],arr[1]);
        
        for(int i=2;i<n;i++)
        {
            int a=dp[i-2]+arr[i];
            int b=dp[i-1];
            dp[i]=max(a,b);
        }
        
        return dp[n-1];
        
        
        
        
 /*       return soln(arr,n-1,dp);*/
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends