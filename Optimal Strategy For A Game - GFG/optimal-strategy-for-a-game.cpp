//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long dp[1001][1001];
	long long func(int i,int j,int arr[])
	{
	    if(i>j) return 0;
	    if(dp[i][j]!=-1) return dp[i][j];
	    long long left = arr[i]+min(func(i+1,j-1,arr),func(i+2,j,arr));
	    long long right = arr[j]+ min(func(i,j-2,arr),func(i+1,j-1,arr));
	    return dp[i][j]=max(left,right); 
	    
	}
	long long maximumAmount(int arr[], int n)
	{
	    memset(dp,-1,sizeof(dp));
		return func(0,n-1,arr);

	}
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends