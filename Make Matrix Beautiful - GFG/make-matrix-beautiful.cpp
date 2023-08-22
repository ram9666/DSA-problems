//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        vector<int>vis(n);
        int need = INT_MIN;
        for(int i=0;i<n;i++)
        {
            int row = 0;
            for(int j=0;j<n;j++)
            {
                row+=matrix[i][j];
            }
            need = max(need,row);
            vis[i] = row;
        
        }
        for(int i=0;i<n;i++)
        {
            int col = 0;
            for(int j=0;j<n;j++)
            {
                col+=matrix[j][i];
            }
            need = max(need,col);
            //vis[i] = row;
        
        }
        int ans=0;
        for(auto x: vis) ans += need-x;
        return ans;
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
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends