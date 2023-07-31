//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> mat)
    {
        //code here
        int n = mat.size();
        int m  = mat[0].size();
        queue<vector<int>>q;
        int val=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                 if(mat[i][j]==2) q.push({i,j,0});
            }
        }
        
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        
        int ans=0;
        while(!q.empty())
        {
            int siz = q.size();
            for(int i=0;i<siz;i++)
            {
                 auto temp = q.front();
                 q.pop();
                 int x= temp[0];
                 int y = temp[1];
                 int val = temp[2];
                 ans=max(ans,val);
                 for(int k=0;k<4;k++)
                 {
                     int nx= x + dx[k];
                     int ny = y+ dy[k];
                     if(nx>=0 and ny>=0 and nx<n and ny<m and mat[nx][ny]==1)
                     {
                         mat[nx][ny]=2;
                         q.push({nx,ny,val+1});
                     }
                 }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                 if(mat[i][j]==1) return -1;
            }
        }
        return ans;
        
        
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends