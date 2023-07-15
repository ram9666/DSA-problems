//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    int dx[4] ={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    void dfs(int x,int y,vector<vector<char>>& grid,vector<vector<int>>& vis)
    {
        vis[x][y]=1;
        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 and ny>=0 and nx<grid.size() and ny<grid[0].size() and grid[nx][ny]=='X' and !vis[nx][ny])
            {
                dfs(nx,ny,grid,vis);
            }
        }
        
    }
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
       int n = grid.size();
       int m = grid[0].size();
       vector<vector<int>>vis(n,vector<int>(m,0));
       int ans=0;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(grid[i][j]=='X' and !vis[i][j])
               {
                   
                   dfs(i,j,grid,vis);
                   ans++;
               }
               
           }
       }
       return ans;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends