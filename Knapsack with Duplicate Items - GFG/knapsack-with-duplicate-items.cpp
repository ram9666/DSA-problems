//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[1001][1001];
    
    int func(int ind,int val[],int wt[],int N,int W)
    {
        if(ind>=N or W<0) return 0;
        if(dp[ind][W]!=-1) return dp[ind][W];
        int npick = func(ind+1,val,wt,N,W);
        int pick = INT_MIN;
        if(wt[ind]<=W)
        {
            pick = val[ind]+func(ind,val,wt,N,W-wt[ind]);
        }
        return dp[ind][W]=max(pick,npick);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        memset(dp,-1,sizeof(dp));
        return func(0,val,wt,N,W);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends