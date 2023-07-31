//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int mod = 1e9+7;
    int func(int i,int j,vector<vector<int>>&mat,vector<vector<int>>&dp,int n, int m)
    {
        if(i==n-1 and j==m-1 and mat[i][j]!=1) return 1;
        if(i>=n or j>=m or mat[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j]%mod;
        int down = func(i+1,j,mat,dp,n,m)%mod;
        int right= func(i,j+1,mat,dp,n,m)%mod;
        return dp[i][j]=(down + right)%mod;
    }
	int FindWays(int n, int m, vector<vector<int>>grid){
	    
	    // Code here
	    vector<vector<int>>mat(n,vector<int>(m,0));
	    for(auto it : grid)
	    {
	        int x = it[0]-1;
	        int y = it[1]-1;
	        mat[x][y]=1;
	    }
	    vector<vector<int>>dp(n,vector<int>(m,-1));
	    return func(0,0,mat,dp,n,m);
	    
	    
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>>blocked_cells;
		for(int i = 0; i < k; i++){
			int x, y;
			cin >> x >> y;
			blocked_cells.push_back({x, y});
		}
		Solution obj;
		int ans = obj.FindWays(n, m, blocked_cells);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends