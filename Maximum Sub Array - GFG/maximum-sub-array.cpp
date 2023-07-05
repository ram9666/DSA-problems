//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here
	    vector<int>ans;
	    int sum=0;
	    int i=0;
	    while(i<n and a[i]<0) i++;
	    if(i==n-1) return ans;
	    
	    for(;i<n;i++)
	    {
	        int cnt=0;
	        vector<int>temp;
	        while(i<n and a[i]>=0)
	        {
	            cnt+=a[i];
	            temp.push_back(a[i]);
	            i++;
	        }
	        if(cnt==sum)
	        {
	            if(temp.size()>ans.size())
	            {
	                ans=temp;
	            }
	        }
	        if(cnt>sum)
	        {
	            sum=cnt;
	            ans=temp;
	        }
	    }
	    return ans;
	    
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends