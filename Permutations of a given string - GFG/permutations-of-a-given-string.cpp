//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    set<string>st;
	    void func(int ind, string S)
	    {
	        if(ind>=S.size())
	        {
	            st.insert(S);
	            return;
	        }
	        for(int i=ind;i<S.size();i++)
	        {
	            swap(S[ind],S[i]);
	            func(ind+1,S);
	            swap(S[i],S[ind]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    func(0,S);
		    // Code here there
		    vector<string>ans;
		    for(auto x: st)
		    {
		        ans.push_back(x);
		    }
		    return ans;
		    
		    
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends