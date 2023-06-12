//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M>N) return -1;
        int start = *max_element(A,A+N);
        int end = accumulate(A,A+N,0);
        while(start<=end)
        {
            int mid = (start+end)/2;
            int sum=0;
            int count =1;
            int i=0;
            while(i<N)
            {
                sum+=A[i];
                if(sum>mid)
                {
                    sum = A[i];
                    count++;
                }
                i++;
            }
            if(count>M) start = mid+1;
            else end = mid-1;
            
        }
        return start;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends