//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
    int mini = INT_MAX;
    int func(int ind,int sum1,int sum,int arr[],int n,vector<vector<int>>&dp)
    {
        if(ind>=n) return 0;
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        mini = min(mini,abs(sum1-sum));
        int npick = func(ind+1,sum1,sum,arr,n,dp);
        int pick = arr[ind]+func(ind+1,sum1+arr[ind],sum-arr[ind],arr,n,dp);
        return dp[ind][sum]=mini;
    
    }
	int minDifference(int arr[], int n)  { 
	    
	    // Your code goes here
	   int sum=0;
	   for(int i=0;i<n;i++)
	   {
	       sum+=arr[i];
	   }
	   vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
	   return func(0,0,sum,arr,n,dp);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends