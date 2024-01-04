//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int singleElement(int arr[] ,int N) {
        // code here
        map<int,int>mp;
        for(int i=0;i<N;i++){
            mp[arr[i]]++;
        }
        vector<pair<int,int>>v;
        if(N==0){
            return 0;
        }
        for(auto m:mp){
            v.push_back({m.second,m.first});
        }
        sort(v.begin(),v.end());
        return (v[0].first == 1) ? v[0].second : -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.singleElement(arr,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends