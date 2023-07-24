//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int arr[], int n){
        //complete the function here
         int mini = INT_MAX;
        
         int l=0;
         int r=n-1;
         while(l<=r)
         {
             int mid = (l+r)>>1;
             if(arr[l]<=arr[mid])
             {
                 mini = min(mini,arr[l]);
                 l=mid+1;
             }
             else 
             {
                 mini = min(mini,arr[mid]);
                 r=mid-1;
             }
         }
         return mini;
         
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends