//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    vector<vector<int>>t;
    
    void solve(vector<int>a,int n, int target, vector<int>&sub, int sum, int index)
    {
        
        if(sum>target)
        {
            return;
        }
        if(sum==target)
        {
            t.push_back(sub);
            return;
        }
        for(int i=index;i<n;i++)
        {
            sub.push_back(a[i]);
            solve(a, n, target,sub, sum+a[i], i);
            sub.pop_back();
        }
                    
    }
    

  
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        sort(A.begin(),A.end());
        set<int>x(A.begin(),A.end());
        vector<int>a(x.begin(),x.end());
        int sum=0;
        vector<int>sub;
        solve(a,a.size(),B, sub, sum, 0);
        
        return t;
        
        
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends