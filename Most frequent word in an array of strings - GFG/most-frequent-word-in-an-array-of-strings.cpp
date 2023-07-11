//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
    public:
    //Function to find most frequent word in an array of strings.
    string mostFrequentWord(string arr[], int n) 
    {
        // code here
        unordered_map<string,int>mp,mp1;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        int maxi=0;
        for(auto x: mp)
        {
            maxi = max(maxi,x.second);
        }
        
        vector<string>v;
        for(auto x: mp)
        {
            if(x.second==maxi) v.push_back(x.first);
        }
        int ind=INT_MIN;
        string ans;
        for(int i=0;i<n;i++)
        {
            if(mp1.find(arr[i])==mp.end())
            {
                mp1[arr[i]]=i;
            }
        }
        
        for(int i=0;i<v.size();i++)
        {
            if(mp1[v[i]]>ind)
            {
                ind=mp1[v[i]];
                ans = v[i];
            }
        }
        return ans;
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.mostFrequentWord(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends