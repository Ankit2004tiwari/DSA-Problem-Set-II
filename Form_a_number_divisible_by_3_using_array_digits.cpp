//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int DivideAndAdd(int n)
    {
        int num = n;
        int res = 0;
        while(num != 0)
        {
            res += num % 10;
            num /= 10;
        }
        return res;
    }
    int isPossible(int N, int arr[]) {
        long long int res = 0;
        for(int i = 0; i < N; i++)
        {
            res += DivideAndAdd(arr[i]);
        }
        return res % 3 == 0 ? 1 : 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution ob;
        cout << ob.isPossible(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends