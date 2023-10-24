//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void sort1(int x,stack<int>&s)
{
    if(!s.empty() && s.top()>x)
    {
        int z=s.top();
        s.pop();
        sort1(x,s);
        s.push(z);
        return;
    }
    else
    {
        s.push(x);
        return;
    }
    
}


void SortedStack :: sort()
{
   //Your code here
   if(s.size()==1)
   {
       return;
   }
   
   int x=s.top();
   s.pop();
   sort();
   sort1(x,s);
 
}