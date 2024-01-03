//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
         // Code here
        int n=S.size();
        int zero=0,one=0,two=0;
        for(int i=0;i<n;i++){
            if(S[i]=='0'){
                zero++;
            }
            else if(S[i]=='1'){
                one++;
            }
            else{
                two++;
            }
        }
        if(zero==0 || one==0 || two==0 ){
            return -1;
        }
        int MIN=INT_MAX;
        int i=0,j=0,count=0;
        unordered_map<char,int>mp;
        while(i<n && j<n){
            mp[S[j]]++;
            if(mp['0']>=1 && mp['1']>=1 && mp['2']>=1){
                MIN=min(MIN,(j-i+1));
                while(i<j-2){
                    mp[S[i]]--;
                    i++;
                    if(mp['0']>=1 && mp['1']>=1 && mp['2']>=1){
                    MIN=min(MIN,(j-i+1));
                }
            }
            }
            if(MIN==3){
                break;
            }
            j++;
        }
        return MIN;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends