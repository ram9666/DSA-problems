//{ Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	    vector<int>v(s.length(),0);
	    int len=0;
	    for(int i=1;i<s.length();)
	    {
	        if(s[i]==s[len])
	        {
	            v[i] = len+1;
	            len++;
	            i++;
	        }
	        else
	        {
	            if(len==0)i++;
	            else
	            {
	                len = v[len-1];
	            }
	        }
	    }
	    return v[s.length()-1];
	    
	}

};

//{ Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}

// } Driver Code Ends