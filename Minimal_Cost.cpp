//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int helper(int i, int k, vector<int>& arr, vector<int>& dp)
    {
        if(i == arr.size()-1) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = INT_MAX;
        
        for(int j = i+1; j <= i+k && j < arr.size(); j++)
        {
            int cost = abs(arr[i] - arr[j]) +  helper(j, k, arr, dp);
            ans = min(ans, cost);
        }
        dp[i] = ans;
        return  dp[i];
    }
    int minimizeCost(int k, vector<int>& arr) {
        vector<int>dp(arr.size(), -1);
        return helper(0, k, arr, dp);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends