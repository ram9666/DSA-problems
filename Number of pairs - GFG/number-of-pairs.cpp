//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    long long countPairs(int X[], int Y[], int m, int n) {
        // code here
        vector<double>vx;
        vector<double>vy;
        for(int i=0;i<m;i++)
        {
            double temp = (double)X[i]/(double)log(X[i]);
            vx.push_back(temp);
        }
        for(int i=0;i<n;i++)
        {
            double temp = (double)Y[i]/(double)log(Y[i]);
            vy.push_back(temp);
        }
        sort(vx.begin(),vx.end());
        sort(vy.begin(),vy.end());
        long long ans=0;
        for(auto z : vy)
        {
            ans+= lower_bound(vx.begin(),vx.end(),z)-vx.begin();
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        int X[m], Y[n];
        for (int i = 0; i < m; i++) {
            cin >> X[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> Y[i];
        }
        Solution ob;
        auto ans = ob.countPairs(X, Y, m, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends