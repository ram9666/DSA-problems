//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string firstRepChar(string s)
{
    //code here.
    string res="-1";
    unordered_map<char,int>mp;
    for(auto x : s)
    {
        mp[x]++;
        if(mp[x]>1)
        {
            res = x;
            break;
        }
    }
    return res;
}