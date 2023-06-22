//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        // code here
        int five =0;
        int ten =0;
        int twenty = 0;
        for(int i=0;i<N;i++)
        {
            if(bills[i]==5)
            {
                five++;
            }
            if(bills[i]==10)
            {
                ten++;
                if(five) five--;
                else return 0;
            }
            if(bills[i]==20)
            {
                twenty++;
                if(ten and five)
                {
                    ten--;
                    five--;
                }
                else if(five>=3) five-=3;
                else return 0;
            }
        }
        return 1;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends