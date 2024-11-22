//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        
        int n = arr.size();
        int i = 0;
        int j = n;
        int prefix = 0;
        int suffix = 0;
        
        while(i < j)
        {
            if(prefix < suffix)
            {
                prefix+= arr[i];
                i++;
            }
            else if(prefix > suffix)
            {
                suffix += arr[j-1];
                j--;
            }
            else 
            {
                if(i+1 < j)
                {
                    prefix += arr[i];
                    i++;
                    suffix += arr[j-1];
                    j--;
                }
                else
                {
                    prefix += arr[i];
                    i++;
                }
            }
        }
        
        if(prefix == suffix) return true;
        return false;
    }
};
/*
    Brute Force :-
    bool canSplit(vector<int>& arr) {
        int prefix = 0;
        int suffix = 0;
        int n = arr.size();
        
        for(int i = 0; i < n; i++)
        {
            prefix += arr[i];
            suffix = 0;
            for(int j = i+1; j < n; j++)
            {
                suffix += arr[j];
            }
            if(prefix == suffix) return true;
        }
        return false;
    }
*/

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t-- > 0) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }

        Solution obj;
        bool res = obj.canSplit(arr);
        cout << (res ? "true" : "false") << endl;
    }
    return 0;
}
// } Driver Code Ends