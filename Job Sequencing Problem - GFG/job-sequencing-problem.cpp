//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    
    static bool compare(Job a, Job b)
    {
        return a.profit>b.profit;
    }
    
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<int>x(n+1,-1);
        sort(arr,arr+n,compare);
        int count=0;
        int profit=0;
        for(int i=0;i<n;i++)
        {
            if(x[arr[i].dead]==-1)
            {
                x[arr[i].dead]=1;
                profit+=arr[i].profit;
                count++;
            }
            else
            {
                int h=arr[i].dead;
                //cout<<h<<endl;
                while(h>0 && x[h]!=-1)
                {
                    h--;
                }
                if(h!=0)
                {
                    x[h]=1;
                    profit+=arr[i].profit;
                    count++;
                }
            }
           // cout<<profit<<endl;
        }
        return {count,profit};
        
        
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends