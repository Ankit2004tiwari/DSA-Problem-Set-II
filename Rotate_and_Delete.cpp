//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int rotateDelete(vector<int> &arr) {
        int k = 1;
        int n = arr.size();
        while(n > 1)
        {
            arr.insert(arr.begin(), arr[n-1]);
            arr.pop_back();
            
            int del = n - k;
            if(del < 0)  del = 0;
            
            arr.erase(arr.begin() + del);
            k++;
            n--;
        }
        return arr[0];
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.rotateDelete(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends