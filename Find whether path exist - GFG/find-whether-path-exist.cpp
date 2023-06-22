//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n = grid.size();
        
        int fs=0;
        int fg=0;
        
        
        int x,y,gx,gy;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    x=i;
                    y=j;
                    fs=1;
                }
                if(grid[i][j]==2)
                {
                    gx=i;
                    gy=j;
                    fg=1;
                }
            }
        }
        if(fs==0 or fg==0) return 0; 
        
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(n,0));
        
        q.push({x,y});
        vis[x][y]=1;
        
        while(!q.empty())
        {
            int k = q.size();
            int sx = q.front().first;
            int sy = q.front().second;
            q.pop();
            if(sx==gx and sy==gy) return true;
            for(int i=0;i<4;i++)
            {
                int nx = sx+dx[i];
                int ny = sy+dy[i];
                if(nx>=0 and ny>=0 and nx<n and ny<n and vis[nx][ny]==0 and grid[nx][ny]!=0)
                {
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
        return 0;
        
        
        
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends