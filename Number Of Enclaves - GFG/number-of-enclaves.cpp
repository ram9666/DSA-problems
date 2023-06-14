//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dx[4] = {0,1,0,-1};
    int dy[4] ={1,0,-1,0};
    void dfs(int x,int y,vector<vector<int>> &grid,vector<vector<int>> &vis)
    {
        vis[x][y]=1;
        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+ dy[i];
            if(nx>=0 and ny>=0 and nx<grid.size() and ny<grid[0].size() and grid[nx][ny]==1 and vis[nx][ny]==0)
            {
                dfs(nx,ny,grid,vis);
            }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code heret
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++)
        {
            if(grid[0][j]==1 and vis[0][j]==0)
            {
                dfs(0,j,grid,vis);
            }
            
            if(grid[n-1][j]==1 and vis[n-1][j]==0)
            {
                dfs(n-1,j,grid,vis);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1 and vis[i][0]==0)
            {
                dfs(i,0,grid,vis);
            }
            
            if(grid[i][m-1]==1 and vis[i][m-1]==0)
            {
                dfs(i,m-1,grid,vis);
            }
        }
        int cnt =0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 and vis[i][j]==0)
                {
                    cnt++;
                    
                }
            }
        }
        return cnt;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends