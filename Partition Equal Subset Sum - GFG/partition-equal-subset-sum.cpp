//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:



int ans=false;
   bool soln(int n, int arr[], int index, int sum,vector<vector<int>>&dp)
    {
        if(sum<0)return false;
        
        if (index == n)
        {
            //cout<<sum<<endl;
           // if(sum==0)
            return sum == 0;
        }
        
        if(dp[index][sum]!=-1)
        {
            return dp[index][sum];
        }
        // Try including the current element in the first partition
        bool include = soln(n, arr, index + 1, sum - arr[index],dp);
    
        // Try excluding the current element from the first partition
        bool exclude = soln(n, arr, index + 1, sum,dp);
    
        // Return true if either including or excluding the current element leads to a partition
        return dp[index][sum]=max(include,exclude);
    }

bool equalPartition(int N, int arr[])
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
    }

    // If the sum is odd, it cannot be partitioned into two equal parts
    if (sum % 2 != 0)
    {
        return false;
    }

    // Call the recursive function to check if it can be partitioned
    vector<vector<int>>dp(N+1,vector<int>(sum+1,-1));
    return soln(N, arr, 0, sum/2,dp);
}

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends