//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
        // Code here 
        vector<int>v(n,0);
        for(int i=0;i<n;i++)
        {
            if(arr[i]=='P') v[i]=1;
        }
        //return v[5];
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(v[i]==0)
            {
                for(int j=k;j>=1;j--)
                {
                    if((i-j)>=0 and v[i-j]==1)
                    {
                        cnt++;
                        v[i]=v[i-j]=-1;
                        break;
                    }
                }
                
                if(v[i]!=-1)
                {
                    for(int j=1;j<=k;j++)
                    {
                       if((i+j)<n and v[i+j]==1)
                       {
                         cnt++;
                         v[i]=v[i+j]=-1;
                         break;
                       }
                    }
                }
            }
            
            
        }
        return cnt;
       // return v[4];
    }
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		Solution obj;
		cout<<obj.catchThieves(arr, n, k) << endl;
	}
	return 0; 
} 


// } Driver Code Ends