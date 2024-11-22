//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int lps(string str) {
        vector<int>lps(str.size(), 0);
        int prefix = 0, suffix = 1;
        
        while(suffix < str.size())
        {
            if(str[prefix] == str[suffix])
            {
                lps[suffix] = prefix+1;
                prefix++;
                suffix++;
            }
            else
            {
                if(prefix == 0)
                {
                    lps[suffix] = 0;
                    suffix++;
                }
                else
                    prefix = lps[prefix-1];
            }
        }
        return lps[str.size()-1];
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}

// } Driver Code Ends