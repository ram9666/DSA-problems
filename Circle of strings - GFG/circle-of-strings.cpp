//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    void dfs(int node, vector<int>&vis, vector<int>adj[])
    {
        vis[node]=1;
        for(auto x : adj[node])
        {
            if(!vis[x])
            {
                dfs(x,vis,adj);
            }
        }
    }
    int isCircle(int N, vector<string> A)
    {
        // code here};
        vector<int>adj[26];
        vector<int>in(26,0),out(26,0),vis(26,0);
        
        for(auto x: A)
        {
            int ch1 = x[0]-'a';
            int ch2 = x.back()-'a';
            adj[ch1].push_back(ch2);
            out[ch1]++;
            in[ch2]++;
        }
        
        for(int i=0;i<26;i++)
        {
            if(in[i]!=out[i]) return 0;
        }
        
        int node;
        for(int i=0;i<26;i++)
        {
            if(vis[i]==0 and out[i]>0)
            {
                node=i;
                break;
            }
        }
        
        dfs(node,vis,adj);
        
        for(int i=0;i<26;i++)
        {
            if(!vis[i] and out[i]>0) return 0;
        }
        
        return 1;
        
        
        
        
        
        
        
        
        
        
        
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string> A;
        string s;
        
        for(int i = 0;i < N; i++)
        {
            cin>>s;
            A.push_back(s);
        }
        
        Solution ob;
        cout<<ob.isCircle(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends