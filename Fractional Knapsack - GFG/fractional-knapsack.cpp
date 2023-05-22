//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    
    
    static bool compare(pair<double,int>a, pair<double,int>b)
    {
        return a.first>b.first;
    }
    
    
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double, int>>x;
        for(int i=0;i<n;i++)
        {
            double c= double(arr[i].value)/double(arr[i].weight);
            x.push_back(make_pair(c,i));
        }
        sort(x.begin(),x.end(),compare);
        double profit=0;
        int i=0;
        while(W>0 && i<n)
        {
            if(W>=arr[x[i].second].weight)
            {
                profit+=arr[x[i].second].value;
                W-=arr[x[i].second].weight;
                i++;
            }
            else
            {
                profit+=x[i].first*W;
                W=0;
            }
        }
        return profit;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends