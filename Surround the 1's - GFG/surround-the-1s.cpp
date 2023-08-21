//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int dx[8] = {0,1,1,1,0,-1,-1,-1};
    int dy[8] = {1,1,0,-1,-1,-1,0,1};
    int func(int x ,int y,vector<vector<int> >& mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int cnt=0;
        for(int i=0;i<8;i++)
        {
            int nx = x+ dx[i];
            int ny = y+dy[i];
            if(nx>=0 and ny>=0 and nx<n and ny<m and mat[nx][ny]==0) cnt++;
        }
        if(cnt==0) return 0;
        return (cnt%2)==0;
    }
    int Count(vector<vector<int> >& mat) {
        // Code here
        int n = mat.size();
        int m = mat[0].size();
        
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j])
                {
                    if(func(i,j,mat)) cnt++;
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends