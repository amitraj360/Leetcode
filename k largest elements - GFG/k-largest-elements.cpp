//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    
	    int maxx=*max_element(arr,arr+n);
	    int aa[maxx+1]={0};
	    for(int i=0;i<n;i++)
	    {
	        aa[arr[i]]++;
	    }
	    int j=0;
	    vector<int>ans;
	    for(int i=maxx;i>=0;i--)
	    {
	        
	        
	        if(k==0 || k<0)
	        {
	            return ans;
	        }
	        if(aa[i]>0)
	        {
	           // cout<<k<<endl;
	            while(aa[i]-- && k--)
	            {
	                ans.push_back(i);
	            }
	            
	        }
	        
	    }
	   
	    return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends