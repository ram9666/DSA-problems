//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        unordered_set<string>st(wordList.begin(),wordList.end());
        vector<vector<string>>ans;
        queue<vector<string>>q;
        q.push({beginWord});
        if(st.find(beginWord)!=st.end()) st.erase(beginWord);
        
        while(!q.empty())
        {
            
            int k = q.size();
            vector<string>v;
            for(int j=0;j<k;j++)
            {
                vector<string>temp = q.front();
                string res = temp.back();
                if(res==endWord) ans.push_back(temp);
                q.pop();
            
                for(int i=0;i<res.size();i++)
                {
                  char orgin = res[i];
                  for(char ch = 'a';ch<='z';ch++)
                  {
                    res[i] = ch;
                    if(st.find(res)!=st.end())
                    {
                        v.push_back(res);
                        temp.push_back(res);
                        q.push(temp);
                        temp.pop_back();
                    }
                  }
                  res[i] =orgin; 
                }
            }
            for(auto a : v) st.erase(a);
            
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends