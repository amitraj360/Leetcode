//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       
       vector<int>temp;
       int s=0;
       for(int i=0;i<n;i++)
       {
           if(s==0 || temp[s-1]<a[i])
           {
               temp.push_back(a[i]);
               s++;
           }
           else
           {
               auto ind=lower_bound(temp.begin(),temp.end(),a[i]);
             //  cout<<ind-temp.begin();
               temp[ind-temp.begin()]=a[i];
           }
       }
       return s;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends