//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int check(string S, int p1, int p2)
    {
        while(p1>=0 and p2<S.size())
        {
            if(S[p1]!=S[p2]) break;
            else
            {
                p1--;
                p2++;
            }
        }
        return p2-p1-1;
    }
    string longestPalin (string S) {
        // code here
        int index=0;
        int mxl=0;
        for(int i=0;i<S.size();i++)
        {
            int val1 = check(S,i,i); //for odd lenghth
            int val2 = check(S,i,i+1); //for even t 
            int maxi = max(val1,val2);
            if(maxi>mxl)
            {
                mxl = maxi;
                index  = i-(mxl-1)/2;
            }
            
        }
        return S.substr(index,mxl);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends