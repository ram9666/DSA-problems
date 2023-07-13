//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& pre) {
	    // Code here
	    vector<int>adj[N];
	    vector<int>ind(N,0);
	    for(auto x : pre)
	    {
	        adj[x.second].push_back(x.first);
	        ind[x.first]++;
	    }
	    queue<int>q;
	    for(int i=0;i<N;i++)
	    {
	        if(ind[i]==0) q.push(i);
	    }
	    vector<int>topo;
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        topo.push_back(node);
	        for(auto edge : adj[node])
	        {
	            ind[edge]--;
	            if(ind[edge]==0) q.push(edge);
	        }
	    }
	    return topo.size()==N;
	    
	     
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends