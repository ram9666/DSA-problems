//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    void func(int x,int y,vector<vector<int>>& grid,vector<vector<int>>& vis,vector<pair<int,int>>&vec,int x0,int y0)
    {
        vis[x][y]=1;
        vec.push_back({x-x0,y-y0});
        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 and ny>=0 and nx<grid.size() and ny< grid[0].size() and grid[nx][ny]==1 and vis[nx][ny]==0)
            {
                func(nx,ny,grid,vis,vec,x0,y0);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>>st;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 and vis[i][j]==0)
                {
                    vector<pair<int,int>>vec;
                    func(i,j,grid,vis,vec,i,j);
                    st.insert(vec);
                }
                
            }
        }
        return st.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends