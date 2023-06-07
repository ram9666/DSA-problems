//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    int func(int n, vector<int>&dp)
	    {
	        if(n<=2) return n;
	        if(dp[n]!=-1) return dp[n];
	        return dp[n] = (func(n-1,dp)+func(n-2,dp))%1000000007;
	        
	    }
		int nthPoint(int n){
		    // Code here
		    vector<int>dp(n+1,-1);
		    return func(n,dp);
		    
		    
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends