//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int atoi(string s) {
        //Your code here
        bool neg=0;
        if(s[0]=='-')
        {
            neg=1;
        }
        int num=0,st;
        st=(neg==0)?0:1;
        for(int i=st;i<s.length();i++)
        {
            if(s[i]>='0' && s[i]<='9')
            {   
                // cout<<s[i]<<endl;
                num=(num*10)+(s[i]-'0');
            }
            else{
                return -1;
            }
        }
        return (neg==0)?num:-num;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends