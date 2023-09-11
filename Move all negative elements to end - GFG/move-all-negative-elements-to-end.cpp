//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        // Your code goes here
        vector<int>temp;
        int i=-1,j=0;
        while(j<n)
        {
            if(arr[j]>=0)
            {
                i++;
                swap(arr[i],arr[j]);
                j++;
            }
            else
            {
                temp.push_back(arr[j]);
              //  cout<<arr[j]<<endl;
                j++;
            }
        }
        i++;
        for(int k=0;k<temp.size();k++)
        {
            arr[i]=temp[k];
            i++;
        }
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}

// } Driver Code Ends