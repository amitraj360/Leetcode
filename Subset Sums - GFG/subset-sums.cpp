//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:

    vector<int>x;
    void solve(vector<int>arr,int sum,int index, int n)
    {
        if(index==n)
        {
            x.push_back(sum);
            return;
        }
        solve(arr, sum+arr[index], index+1,n);
        solve(arr,sum, index+1,n);
    }

    

        

    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        solve(arr, 0, 0,N);
        return x;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends