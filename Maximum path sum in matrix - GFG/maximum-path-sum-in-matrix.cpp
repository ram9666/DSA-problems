//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dx[3] = {1,1,1};
    int dy[3]={-1,0,1};
    
    int func(int i,int j,vector<vector<int>>&mat,vector<vector<int>>&dp)
    {
        if(i==mat.size()-1) return mat[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi = 0;
        for(int k=0;k<3;k++)
        {
            int nx = i+dx[k];
            int ny = j+dy[k];
            if(nx>=0 and ny>=0 and nx<mat.size() and ny<mat.size())
            {
                int res = mat[i][j] +func(nx,ny,mat,dp);
                maxi = max(maxi,res);
            }
        }
        return dp[i][j] = maxi;
        
        
    }
    int maximumPath(int N, vector<vector<int>> mat)
    {
        int n = mat.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int maxi = INT_MIN;
        for(int i=0;i<mat.size();i++){
            maxi = max(maxi,func(0,i,mat,dp));
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends