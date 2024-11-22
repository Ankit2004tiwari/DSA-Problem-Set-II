//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        
        long long total_sum = 0;
        long long prev = 0;
        for(int i = 0; i < n; i++)
        {
            total_sum += a[i];
            prev = prev + i * (long long)a[i];
        }
    
        long long maxi = prev;
        
        for(int i = 1; i < n; i++)
        {
            long long int temp = prev - (total_sum - a[i-1]) + (long long)(a[i-1] * (long long)(n-1));
            maxi = maxi < temp ? temp : maxi;
            prev = temp;
        }
        return maxi;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends