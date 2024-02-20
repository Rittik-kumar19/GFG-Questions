//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
    bool solve(int ind,int n,string s,unordered_set<string> st)
    {
        if(ind == n)
        return true;
        string k;
        for(int i=1; ind+i<=n; i++)
        {
            k = s.substr(ind,i);
            if(st.find(k) != st.end())
            {
                if(solve(ind+i,n,s,st) == true)
                return true;
            }
        }
        return false;
    }
    int wordBreak(int n, string s, vector<string> &dictionary) {
        //code here
        unordered_set<string> st;
        for(int i=0; i<n; i++)
        st.insert(dictionary[i]);
        bool ans = solve(0,s.size(),s,st);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends