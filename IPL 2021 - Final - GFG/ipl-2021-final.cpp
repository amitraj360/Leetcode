//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        stack<char>s1;
        stack<pair<int,int>>s2;
        int maxx=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                s1.push('(');
            }
            else
            {
                if(!s1.empty())
                {
                    s1.pop();
                    int t=s1.size();
                    if(!s2.empty())
                    {
                        int p=2;
                        while(s2.size()!=0 && s2.top().second>=t  )
                        {
                            int a=s2.top().first;
                            s2.pop();
                            p+=a;
                            
                        }
                        maxx=max(p,maxx);
                        s2.push(make_pair(p,t));
                    }
                    else
                    {
                        s2.push(make_pair(2,s1.size()));
                      maxx=max(2,maxx);
                        
                    }
                    
                    
                }
                else
                {
                    while(!s2.empty())
                    s2.pop();
                    while(!s1.empty())
                    s1.pop();
                }
                
            }
            // cout<<maxx<<endl;
            // if(!s2.empty())
            // {
            //     cout<<s2.size()<<" "<<s2.top().first<<" "<<s2.top().second<<endl;
            // }
        }
        return maxx;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends