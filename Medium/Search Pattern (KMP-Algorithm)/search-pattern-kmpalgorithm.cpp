//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector<int> LPs(string s) {
	    // Your code goes here
	    int n=s.length();
	    
	    vector<int>LPS(n,0);
	    if(n==1) return {0};
	    int pref=0,suff=1;
	    
	    while(suff<n){
	        
	        if(s[pref]==s[suff]){
	            LPS[suff]=pref+1;
	            pref++;
	            suff++;
	        }else{
	            
	            if(pref == 0){
	                LPS[suff] = 0;
	                suff++;
	            }else{
	                pref = LPS[pref-1];
	            }
	        }
	    }
	    return LPS;
	}
	
    vector<int> search(string pat, string txt) {
       
        int n = txt.size();
        int m = pat.size();
        
        
        vector<int>ans;
        if(n<m) return ans;
        
        vector<int>lps(m,0);
        lps = LPs(pat);
        
        int first = 0,second=0;
        
        while(first < n && second <m){
            if(txt[first] == pat[second]){
                first++;
                second++;
                
                if(second == m){
                    ans.push_back(first-second+1);
                    second =lps[second -1];
                }
            }else{
                if(second == 0){
                    first++;
                }else{
                    second = lps[second -1];
                }
            }
            
            if(second == m){
                ans.push_back(first-second);
                second =lps[second -1];
            }
        }
        
        return ans;
        
        
    }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends