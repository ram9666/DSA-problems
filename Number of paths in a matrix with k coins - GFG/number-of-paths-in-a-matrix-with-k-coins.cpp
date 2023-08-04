//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    long long dp[101][101][101];
    long long func(int x,int y,int sum,int n,int k,vector<vector<int>>&arr)
    {
          if(x==n-1 and y==n-1)
          {
              return (sum==k)?1:0;
          }
         if(dp[x][y][sum]!=-1) return dp[x][y][sum];
         long long r=0;
         if(x<n and y+1<n) r= func(x,y+1,sum+arr[x][y+1],n,k,arr);
         long long d=0;
         if(x+1<n and y<n) d = func(x+1,y,sum+arr[x+1][y],n,k,arr);
         return dp[x][y][sum]=(r+d);
        
        
    }
    
    long long numberOfPath(int n, int k, vector<vector<int>> arr){
        
        // Code Here
        memset(dp,-1,sizeof(dp));
        return func(0,0,arr[0][0],n,k,arr);
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n+1, vector<int>(n+1, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends