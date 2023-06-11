//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	class node
	{
	    public:
	    int val;
	    node *left;
	    node *right;
	    node(int item)
	    {
	       val=item;
	       left=right=NULL;
	    }
	};
	
	class cmp
	{
	    public:
	    bool operator()(node *a,node *b)
	    {
	        return a->val > b->val;
	    }
	};
	
	
	    void preorder(vector<string>&ans,node *temp, string s)
	    {
	       // if(temp->left!=NULL)
	       // {
	       //     string x=s;
	       //     x+='0';
	       //     preorder(ans,temp->left,x);
	       // }
	       // if(temp->right!=NULL)
	       // {
	       //     string x=s;
	       //     x+='1';
	       //     preorder(ans,temp->right,x);
	       // }
	       // ans.push_back(s);
	       // return;
	       
	       if(temp==NULL)
	       {
	           return;
	       }
	       
	       if(temp->left==NULL && temp->right==NULL)
	       {
	           ans.push_back(s);
	           return;
	       }
	       preorder(ans, temp->left,s+'0');
	       preorder(ans,temp->right,s+'1');
	        
	    }
	   
	
	
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
		    priority_queue<node*,vector<node*>,cmp>pq;
		    for(auto i:f)
		    {
		        node* temp=new node(i);
		        pq.push(temp);
		    }
		    
		    while(pq.size()>1)
		    {
		        node *a=pq.top();
		        pq.pop();
		        node *b=pq.top();
		        pq.pop();
		        //cout<<a->val<<b->val<<endl;
		        node *temp=new node(a->val+b->val);
		       // cout<<temp->val<<endl;
		            temp->left=a;
		            temp->right=b;
		        pq.push(temp);
		    }
		    node *temp=pq.top();
		    vector<string>ans;
		    preorder(ans, temp,"");

		    
		    return ans;
		    
		    
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends