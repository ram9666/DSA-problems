//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int>ans;
    void func(int ind,int sum,vector<int>&arr)
    {
        if(ind==arr.size())
        {
            ans.push_back(sum);
            return ;
        }
        func(ind+1,sum+arr[ind],arr);
        func(ind+1,sum,arr);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
       func(0,0,arr);
       sort(a)
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
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends