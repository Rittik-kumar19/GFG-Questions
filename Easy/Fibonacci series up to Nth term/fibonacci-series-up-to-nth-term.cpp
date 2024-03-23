//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int>v;
    int M=1000000007;
    vector<int> Series(int n) {
        // Code here
        int f=0;
        int s=1;
        int d=n-1;
        v.push_back(0);
        v.push_back(1);
        while(d--){
            int temp=(f+s)%M;
            v.push_back(temp);
            f=s;
            s=temp;
        }
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends