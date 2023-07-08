//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colournode,.
    
    bool isCheck(int node,bool graph[101][101],int col[],int color,int n)
    {
        for(int i=0;i<n;i++)
        {
            if(i!=node and graph[i][node]==1 and col[i]==color) return false;
        }
        return true;
    }
    bool func(int node,bool graph[101][101],int col[],int m, int n)
    {
        if(node==n) return true;
        for(int i=1;i<=m;i++)
        {
            if(isCheck(node,graph,col,i,n))
            {
                col[node]=i;
                if(func(node+1,graph,col,m,n)) return true;
                col[node]=0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int col[n]={0};
        if(func(0,graph,col,m,n)) return true;
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends