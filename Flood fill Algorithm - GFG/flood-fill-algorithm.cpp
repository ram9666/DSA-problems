//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};

    void func(int sr,int sc,vector<vector<int>>&image,int newColor,vector<vector<int>>&vis,int old)
    {
        image[sr][sc]=newColor;
        vis[sr][sc]=1;
        for(int i=0;i<4;i++)
        {
            int x = sr+dx[i];
            int y = sc+dy[i];
            if(x>=0 and y>=0 and x<image.size() and y<image[0].size() and vis[x][y]==0 and image[x][y]==old)
            {
                func(x,y,image,newColor,vis,old);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n = image.size();
        int m  = image[0].size();
        int old = image[sr][sc];
        vector<vector<int>>vis(n,vector<int>(m,0));
        func(sr,sc,image,newColor,vis,old);
        return image;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends