//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    static bool compare(pair<int,int>a, pair<int,int>b)
    {
        return a.first<b.first;
    }
    
    int findPlatform(int arr[], int dept[], int n)
    {
    	// Your code here
        vector<pair<int,int>>x;
        for(int i=0;i<n;i++)
        {
            x.push_back(make_pair(dept[i],i));
        }
        sort(x.begin(),x.end(),compare);
        int count=0;
        vector<int>track;
        for(auto i:x)
        {
            if(track.empty())
            {
                track.push_back(i.first);
            }
            else
            {
                int flag=0;
                int index=-1;
                int val=0;
                int temp=arr[i.second];
                for(int j=0;j<track.size();j++)
                {
                    if(temp>track[j])
                    {
                       if(val<track[j])
                       {
                           val=track[j];
                           index=j;
                       }
                    }
                }
                if(index==-1)
                {
                    track.push_back(i.first);
                }
                else
                {
                    track[index]=i.first;
                }
            }
        }
        
    	
    	
    	return track.size();
    	
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends