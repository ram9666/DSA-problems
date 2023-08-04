//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string s){
        // code here 
        int n = s.size();
        int num=1;
        string res="";
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='D')
            {
                st.push(num);
                num++;
            }
            else 
            {
                st.push(num);
                num++;
                while(!st.empty())
                {
                    res+=to_string(st.top());
                    st.pop();
                }
            }
        }
        st.push(num);
        while(!st.empty())
        {
            res+=to_string(st.top());
            st.pop();
        }
        
        return res;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends