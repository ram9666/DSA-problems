//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here
            string ans="";
            string temp = "";
            for(int i=s.size()-1;i>=0;i--)
            {
                if(s[i]-'0'>=0 and s[i]-'0'<=9)
                {
                    temp=s[i]+temp;
                }
                else
                {
                    ans=ans+temp+s[i];
                    temp ="";
                }
            }
            ans+=temp;
            return ans;
            

            
        
            
            
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends