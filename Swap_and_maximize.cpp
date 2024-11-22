//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        // code here
        
        int m = arr.size()-1;
        int n = 0;
        vector<int> arr1;
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < arr.size(); i++)
        {
            if(i % 2 == 0)
                arr1.push_back(arr[m--]);
            else
                arr1.push_back(arr[n++]);
        }
        
        int ans = 0;
        
        for(int i = 0; i < arr.size()-1; i++)
        {
             ans += abs(arr1[i] - arr1[i+1]);
        }
        ans += abs(arr1[arr1.size()-1] - arr1[0]);
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends