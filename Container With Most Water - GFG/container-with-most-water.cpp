//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long A[], int len)
{
    // Your code goes here
    long long maxi=0;
    int l=0;
    int r=len-1;
    while(l<r)
    {
        long long ans=(r-l)*min(A[r],A[l]);
        maxi = max(ans,maxi);
        if(A[l]<A[r]) l++;
        else r--;
    }
    return maxi;
    
    
    
    
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends