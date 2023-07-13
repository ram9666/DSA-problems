//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string s)
    {
        //code \\\here.
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            string temp="";
            string dot="";
            while(s[i]!='.' and i<s.size())
            {
                temp+=s[i];
                i++;
            }
            if(s[i]=='.') dot+='.';
            reverse(temp.begin(),temp.end());
            ans+=temp +dot;
        }
        ans;
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
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends