//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int dp[100001];
    
    int func(int n)
    {
        if(n == 2 || n==3 || n==4 || n==5 || n==6 || n==8 || n==9) return false;
        if( n == 1) return true;
   
        int sum=0;
        while(n)
        {
            int k = n%10;
            sum+=k*k;
            n = n/10;
        }
        n = sum;
        return func(n);
        
    
    }
    int nextHappy(int N){   
        
        
       N++;
       while(func(N)==0)
       {
           
           N++;
       }
       return N;
       return -1;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends