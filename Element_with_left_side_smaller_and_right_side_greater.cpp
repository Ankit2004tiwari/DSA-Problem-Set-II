//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findElement(vector<int> &arr) {
        int n = arr.size();
        int leftMax[n];
        leftMax[0] = arr[0];
        
        for(int i = 1; i < n; i++)
            leftMax[i] = max(arr[i], leftMax[i-1]);
        
        int rightMin[n];
        rightMin[n-1] = arr[n-1];
        
        for(int i = (n-2); i >= 0; i--)
            rightMin[i] = min(arr[i], rightMin[i+1]);
        
        for(int i = 1; i < (n-1); i++)
            if(leftMax[i] == rightMin[i]) return rightMin[i];
            
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.findElement(arr);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends