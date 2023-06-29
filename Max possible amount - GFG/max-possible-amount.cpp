//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int dp[1001][1001];
	int func(int i,int j,int arr[])
	{
	    if(i>j) return 0;
	    if(dp[i][j]!=-1) return dp[i][j];
	    int left = arr[i]+min(func(i+1,j-1,arr),func(i+2,j,arr));
	    int right = arr[j]+ min(func(i,j-2,arr),func(i+1,j-1,arr));
	    return dp[i][j]=max(left,right); 
	    
	}
	int maxAmount(int arr[], int n)
	{
	    memset(dp,-1,sizeof(dp));
		return func(0,n-1,arr);

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
	    cout << ob.maxAmount(a, n) << "\n";

	     
    }
    return 0;
}

// } Driver Code Ends