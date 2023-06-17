//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int func(int ind,int prev,int arr[],int n,vector<vector<int>>&dp)
	{
	    if(ind>=n) return 0;
	    if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
	    int npick = func(ind+1,prev,arr,n,dp);
	    int pick = INT_MIN;
	    if(prev==-1 or arr[prev]<arr[ind])
	    {
	        pick = arr[ind]+func(ind+1,ind,arr,n,dp);
	    }
	    return dp[ind][prev+1]=max(pick,npick);
	}
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
	    return func(0,-1,arr,n,dp);
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
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends