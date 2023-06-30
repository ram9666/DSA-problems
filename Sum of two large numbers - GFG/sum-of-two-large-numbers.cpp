//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string findSum(string X, string Y) {
        // Your code goes here
        
        int i=0;
        while(X[i]=='0')i++;
        X = X.substr(i);
        int j=0;
        while(Y[j]=='0')j++;
        Y = Y.substr(j);
        string maxi,mini;
        if(X.size()>Y.size())
        {
            maxi = X;
            mini=Y;
        }
        else
        {
             maxi = Y;
             mini=X;
        }
        int m = maxi.size();
        
        while(mini.size()<maxi.size())
        {
            mini = '0'+mini;
        }
        int n=mini.size();
        int car=0;
        string ans = "";
        
        for(int i=n-1;i>=0;i--)
        {
            int num1= mini[i]-'0'+ maxi[i]-'0'+car;
            car = num1/10;
            ans = to_string(num1%10)+ans;
        }
        if(car)
        {
            ans = to_string(car)+ans;
        }
        if(ans.size()==0) return "0";
        return ans;
        
        
        
        
        
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
// } Driver Code Ends