//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string s) {
        // Code here
        int length = s.size();
        int ans = -1;
        int start = 0;
        int z = 0, o = 0, t = 0;
        for(int end = 0;end<length;end++){
            if(s[end]=='0')z++;
            if(s[end]=='1')o++;
            if(s[end]=='2')t++;
            
            while(z and o and t){
                ans = (ans == -1) ? (end-start +1): min(ans, end-start +1);
                if(s[start]=='0')z--;
                if(s[start]=='1')o--;
                if(s[start]=='2')t--;
                
                start++;
            }
        }
        return ans;
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