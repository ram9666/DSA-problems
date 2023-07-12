//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int optimalKeys(int N){
        // code here
        if(N<=6) return (long long)N;
        vector<long long>dp(N+1);
        for(long long i=1;i<=6;i++)
        {
            dp[i]=i;
        }
        
        for(long long i=7;i<=N;i++)
        {
            dp[i] = max({2*dp[i-3],3*dp[i-4],4*dp[i-5]});
        }
        return dp[N];
       
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.optimalKeys(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends