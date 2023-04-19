//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        // code here
        //cout<<S<<endl;
        for(int i=0;i<N;i++)
        {
            if(S[i]=='1')
            {
                int t=X;
                int j=i-1;
                while(t-- && j>=0)
                {
                    //if(S[j]=='2') break;
                    if(S[j]=='1')continue;
                    S[j]='2';
                    j--;
                }
                t=X;
                j=i+1;
                while(t-- && j<N)
                {
                    //if(S[j]=='2') break;
                  //  cout<<"asas";
                    if(S[j]=='1') continue;
                    S[j]='2';
                    j++;
                }
            }
           // cout<<S<<endl;
        }
       // cout<<S<<endl;
        for(int i=0;i<N;i++)
        {
            if(S[i]=='0')
            {
                return 0;
            }
        }
        
        
        return 1;
        
        
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends