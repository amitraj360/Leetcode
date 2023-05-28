//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    
    
    
    
    void dfs(int i, int j,int m, int n,vector<vector<char>>& grid)
    {
        grid[i][j]='0';
        if(i-1>=0 && grid[i-1][j]=='1')
        {
            dfs(i-1,j,m,n,grid);
        }
        if(i+1<m && grid[i+1][j]=='1')
        {
            dfs(i+1,j,m,n,grid);
        }
        if(j-1>=0 && grid[i][j-1]=='1')
        {
            dfs(i,j-1,m,n,grid);
        }
        if(j+1<n && grid[i][j+1]=='1')
        {
            dfs(i,j+1,m,n,grid);
        }
        if(j+1<n && i+1<m && grid[i+1][j+1]=='1')
        {
            dfs(i+1,j+1,m,n,grid);
        }
        if(j-1>=0 && i-1>=0 && grid[i-1][j-1]=='1')
        {
            dfs(i-1,j-1,m,n,grid);
        }
        if(j-1>=0  && i+1<m && grid[i+1][j-1]=='1')
        {
            dfs(i+1,j-1,m,n,grid);
        }
        if(j+1>=0 && i-1>=0 && grid[i-1][j+1]=='1')
        {
            dfs(i-1,j+1,m,n,grid);
        }
        return;
    }
    
    
    
    
    
    
    
    
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int m=grid.size();
        int n=grid[0].size();
        
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    grid[i][j]='0';
                    count++;
                    dfs(i,j,m,n,grid);
                }
            }
        }
        
        return count;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends