//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int func(int i,int j,string str,vector<vector<int>>&dp)
    {
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(str[i]==str[j])
        {
            return dp[i][j] = func(i+1,j-1,str,dp);
        }
        else return dp[i][j] = 1 +min(func(i+1,j,str,dp),func(i,j-1,str,dp));
    }
    int countMin(string str){
    //complete the function here
    int n=str.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return func(0,str.size()-1,str,dp);
       
       
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends