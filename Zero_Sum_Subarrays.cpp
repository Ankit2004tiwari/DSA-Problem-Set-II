//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &A, int N) {
        
        unordered_map<long long int, int> prefixSum;
        long long int sum = 0;
        long long int cnt = 0;
        
        for(int i = 0; i < N; i++)
        {
            sum += A[i];
            
            if(sum == 0)
                cnt++;
                
            if(prefixSum.find(sum) != prefixSum.end())
                cnt += prefixSum[sum];
                
            prefixSum[sum]++;
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends