//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    // your code here
    int n = s.size();
    if(n%2) return -1;
    int open =0;
    int res=0;
    for(auto x : s)
    {
        if(x=='{') open++;
        else
        {
            if(open==0)
            {
                res++;
                open++;
            }
            else
            {
                open--;
            }
        }
    }
    return res+open/2;
    
    
}