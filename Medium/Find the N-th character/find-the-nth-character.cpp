//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char getans(char curr, int p, int ind){
        if(ind == 0){
            return curr;
        }
        if(ind >= (p / 2)){
            return getans(curr == '1' ? '0' : '1', p/2, ind - (p/2));
        }
        return getans(curr, p/2, ind);
    }
    char nthCharacter(string s, int r, int n) {
        int p = pow(2, r);
        return getans(s[n/p], p, n % p);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends