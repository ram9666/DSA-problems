//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	int mod = 1e9+7;
	ll countStrings(int n) {
	    // code here
	     vector<ll>dp(n+1,0);
	     
	     dp[0]=0;
	     dp[1]=2;
	     dp[2]=3;
	    
	     for(int i=3;i<=n;i++)
	     {
	         dp[i] = (dp[i-1]+dp[i-2])%mod;
	     }
	     return dp[n];
	     
	     
	     
	     
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends