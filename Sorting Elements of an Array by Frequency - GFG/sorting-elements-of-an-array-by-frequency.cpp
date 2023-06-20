#include <iostream>
#include<bits/stdc++.h>
using namespace std;
static bool comp(pair<int,int>&a,pair<int,int>&b){
    if(a.first==b.first) return a.second<b.second;
    return a.first>b.first;
}
vector<int> func(int arr[],int n)
{
    vector<int>ans;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    vector<pair<int,int>>v;
    for(auto x : mp)
    {
        v.push_back({x.second,x.first});
    }
    sort(v.begin(),v.end(),comp);
    
    
    for(auto x: v){
        int num = x.second;
        int count = x.first;
        while(count--)
        {
            ans.push_back(num);
            
        }
    }
    return ans;
    
}

int main() {
	//code
	int N;
	cin>>N;
	while(N--){
	    int n;
	    cin>>n;
	    int arr[n];
	    vector<int>v;
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    v = func(arr,n);
	    for(int i=0;i<n;i++){
	        cout<<v[i]<<" ";

	    }
	    cout<<endl;
	    
	}
	
	
	return 0;
	
}