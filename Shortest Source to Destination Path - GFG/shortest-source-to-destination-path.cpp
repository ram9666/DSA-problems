//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int n, int m, vector<vector<int>>mat, int x, int y) {
        // code here
        if(mat[0][0]==0 or mat[x][y]==0) return -1;
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        queue<vector<int>>q;
        q.push({0,0,0});
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        while(!q.empty())
        {
            int siz = q.size();
            for(int i=0;i<siz;i++)
            {
                
                auto v = q.front();
                q.pop();
                int a = v[0];
                int b = v[1];
                int val= v[2];
                
                if(a==x and b==y) return val;
                
                for(int j=0;j<4;j++)
                {
                    int nx = a + dx[j];
                    int ny  = b+ dy[j];
                    if(nx>=0 and ny>=0 and nx<n and ny<m and mat[nx][ny]==1 and !vis[nx][ny])
                    {
                         vis[nx][ny]=1;
                         q.push({nx,ny,val+1});
                    }
                }
                
            }
        }
        return -1;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends