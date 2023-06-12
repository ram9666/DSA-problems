//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    // code here
	    sort(arr,arr+n);
	    for(int i=n-1;i>=2;i--)
	    {
	        int c= arr[i]*arr[i];
	        int s=0;
	        int e= i-1;
	        while(s<e)
	        {
	            int sum = arr[s]*arr[s]+arr[e]*arr[e];
	            if(sum==c) return 1;
	            else if(sum<c)
	            {
	                s++;
	            }
	            else e--;
	        }
	    }
	    return 0;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}

// } Driver Code Ends