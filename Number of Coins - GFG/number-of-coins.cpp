//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int func(int ind,int sum,int coins[], int n,vector<vector<int>>&dp)
	{
	    if(sum==0) return 0;
	    if(ind==n-1)
	    {
	        if(sum%coins[ind]==0)
	        {
	            return sum/coins[ind];
	        }
	        return 1e9;
	    }
	    
	    
	    if(dp[ind][sum]!=-1) return dp[ind][sum];
	    int npick = func(ind+1,sum,coins,n,dp);
	    int pick=INT_MAX;
	    if(coins[ind]<=sum)
	    {
	        pick=1+func(ind,sum-coins[ind],coins,n,dp);
	    }
	    return dp[ind][sum] = min(pick,npick);
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    vector<vector<int>>dp(M+1,vector<int>(V+1,-1));
	    int ans =func(0,V,coins,M,dp);
	    
	    if(ans==1e9) return -1;
	    return ans;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends