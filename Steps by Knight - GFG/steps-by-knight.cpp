//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    
   
	int minStepToReachTarget(vector<int>&pos,vector<int>&tar,int N)
	{
	    // Code here
	    int dx[8] = {2,2,-2,-2,1,1,-1,-1};
        int dy[8] = {1,-1,1,-1,2,-2,2,-2};
	    vector<vector<int>>vis(N,vector<int>(N,0));
	    queue<pair<pair<int,int>,int>>q;
	    int x = pos[0]-1;
	    int y=pos[1]-1;
	    vis[x][y]=1;
	    int gx = tar[0]-1;
	    int gy = tar[1]-1;
	    q.push({{x,y},0});
	    while(!q.empty())
	    {
	        int k = q.size();
	        int sx = q.front().first.first;
	        int sy = q.front().first.second;
	        int count  = q.front().second;;
	        q.pop();
	        if(sx==gx and sy==gy) return count;
	        for(int i=0;i<8;i++)
	        {
	            int nx = sx+dx[i];
	            int ny  = sy+dy[i];
	            if(nx>=0 and ny>=0 and nx<N and ny<N and vis[nx][ny]==0)
	            {
	                vis[nx][ny]=1;
	                q.push({{nx,ny},count+1});
	            }
	        }
	    }
	    return -1;
	    
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends