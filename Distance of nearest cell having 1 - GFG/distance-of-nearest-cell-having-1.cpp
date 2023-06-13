//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    

	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code ivecn
	    int dx[8]= {0,1,0,-1};
        int dy[8] = {1,0,-1,0};
	    int n = grid.size();
	    int m = grid[0].size();
	    queue<pair<pair<int,int>,int>>q;
	    
	    vector<vector<int>>vis(n,vector<int>(m,0));
	    vector<vector<int>>dis(n,vector<int>(m,0));
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==1)
	            {
	               q.push({{i,j},0});
	               vis[i][j]=1;
	            }
	        }
	    }
	    
	    while(!q.empty())
	    {
	        int x = q.front().first.first;
	        int y = q.front().first.second;
	        int k = q.front().second;
	        q.pop();
	        dis[x][y] = k;
	        for(int i=0;i<4;i++)
	        {
	            int nx = x + dx[i];
	            int ny = y+ dy[i];
	            if(nx>=0 and ny>=0 and nx<n and ny<m and grid[nx][ny]==0 and vis[nx][ny]==0)
	            {
	                vis[nx][ny]=1;
	                q.push({{nx,ny},k+1});
	            }
	        }
	    }
	    return dis;
	    
	}
	
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends