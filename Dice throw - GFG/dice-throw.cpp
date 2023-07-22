//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long dp[51][51];
    
    long long func(int dices,int tar,int val)
    {
        if(tar<0) return 0;
        if(dices==0 and tar!=0) return 0;
        if(dices==0 and tar==0) return 1;
        if(dp[dices][tar]!=-1) return dp[dices][tar];
        
        long long ans=0;
        for(int i=1;i<=val;i++)
        {
            ans+=func(dices-1,tar-i,val);
        }
        return dp[dices][tar]=ans;
    }
    long long noOfWays(int M , int N , int X) {
        // code here
        memset(dp,-1,sizeof(dp));
        return func(N,X,M);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends