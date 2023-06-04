//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
   map<char,vector<pair<int,int>>>mp;
   set<string>ans;
   int vis[51][51];

   bool solve(int i,int j,int ind,int n,string &word){
     
       if(ind>=n)return true;
       vis[i][j]=1;
       bool a=false;
       for(auto x:mp[word[ind]]){
           
         if(max(abs(x.first-i),abs(x.second-j))<=1 &&vis[x.first][x.second]==0 &&  solve(x.first,x.second,ind+1,n,word )){
             a=true;
             break;
         }
         
       }
       
       vis[i][j]=0;
       return a;
       
    }

	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dict) {
	memset(vis,0,sizeof(vis));
	
	for(int i=0;i<board.size();i++){
	    for(int j=0;j<board[0].size();j++){
	        mp[board[i][j]].push_back({i,j});
	    }
	}
	
	for(int i=0;i<dict.size();i++){
	    
	    for(auto xy:mp[dict[i][0]]){
	    if(solve(xy.first,xy.second,1,dict[i].size(),dict[i]))ans.insert(dict[i]);
	    }
	    
	}
	  
	  vector<string>finalans(ans.begin(),ans.end());
	  return finalans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends