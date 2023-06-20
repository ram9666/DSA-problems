//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	
	int count(int arr[], int n, int x) {
	    // code here
	    int i=0;
	    int j=n-1;
	    int low=-1;
	    while(i<=j)
	    {
	        int mid = (i+j)>>1;
	        if(x==arr[mid])
	        {
	            low = mid;
	            j = mid-1;
	        }
	        else if(x<arr[mid]){
	            j = mid-1;
	        }
	        else
	        {
	            i = mid+1;
	        }
	    }
	    
	     i=0;
	     j=n-1;
	    int high=-1;
	    while(i<=j)
	    {
	        int mid = (i+j)>>1;
	        if(x==arr[mid])
	        {
	            high = mid;
	            i = mid+1;
	        }
	        else if(x>arr[mid]){
	            i = mid+1;
	        }
	        else
	        {
	            j = mid-1;
	        }
	    }
	    
	    if(low ==-1) return 0;
	    return high-low+1;
	   
	   
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends