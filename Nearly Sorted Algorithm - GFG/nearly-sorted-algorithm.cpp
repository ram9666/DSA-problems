#include <iostream>
#include<bits/stdc++.h>
using namespace std;


vector <int> nearlySorted(int arr[], int num, int K){
        // Your code here
        priority_queue<int,vector<int>,greater<int>>q;
        for(int i=0;i<num;i++)
        {
            q.push(arr[i]);
        }
        
        vector<int>v;
        while(q.size())
        {
            v.push_back(q.top());
            q.pop();
        }
        return v;
}
int main() {
	//code
	int N;
	cin>>N;
	while(N--)
	{
	    int n,k;
	    cin>>n>>k;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    vector<int>ans = nearlySorted(arr,n,k);
	    for(auto it : ans) cout<<it<<" ";
	    cout<<endl;
	}
	return 0;
}