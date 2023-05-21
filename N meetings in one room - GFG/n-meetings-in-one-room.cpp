//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    static bool compare(pair<int,int>a, pair<int,int>b)
    {
        return a.first<b.first;
    }
    
    
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>>x;
        for(int i=0;i<n;i++)
        {
            x.push_back(make_pair(end[i],i));
        }
        sort(x.begin(),x.end(),compare);
        
        int t=-1;
        int count=0;
        for(auto i:x)
        {
            if(start[i.second]>t)
            {
                t=i.first;
                count++;
            }
        }
        
        
        
        
        
        
        
        // for(auto i:x)
        // {
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        return count;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends