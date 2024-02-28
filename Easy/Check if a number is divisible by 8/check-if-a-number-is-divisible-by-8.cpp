//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
   int DivisibleByEight(string s)
    {
        int len=s.size();
        if(len<=3)
        {
            int i=len-1;
            int sum=0;
            int k=1;
            while(s[i]!='\0')
            {
                sum+=s[i]*k;
                k*=10;
                i--;
            }
            if(sum%8)
            {
                return -1;
            }
            return 1;
        }
        else
        {
            int num=s[len-1]+s[len-2]*10+s[len-3]*100;
            if(num%8)
            {
                return -1;
            }
            return 1;
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends