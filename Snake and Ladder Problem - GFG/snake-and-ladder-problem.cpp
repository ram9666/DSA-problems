//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        // code here
        unordered_map<int,int>snake,lad;
        int n = 2*N;
        for(int i=1;i<n;i+=2)
        {
            if(arr[i-1]<arr[i]) lad[arr[i-1]]=arr[i];
            if(arr[i-1]>arr[i]) snake[arr[i-1]]=arr[i];
        }
        
        queue<pair<int,int>>q;
        q.push({1,0});
        int ans;
        while(!q.empty())
        {
            int node = q.front().first;
            int val = q.front().second;
            q.pop();
            if(node==30)
            {
                ans=val;
                break;
            }
            for(int i=1;i<=6;i++)
            {
                int x = node+i;
                if(lad.find(x)!=lad.end()) q.push({lad[x],val+1});
                else if(snake.find(x)!=snake.end()) q.push({snake[x],val+1});
                else q.push({x,val+1});
                
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends