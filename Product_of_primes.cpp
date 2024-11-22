//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool primeNum(long long num)
    {
        for(int i = 2; i*i <= num; i++)
        {
            if(num % i == 0)
                return false;
        }
        return true;
    }
    long long primeProduct(long long L, long long R){
        long long int ans = 1;
        for(long long i = L; i <= R; i++)
        {
            if(primeNum(i))
                ans = (ans * i) % 1000000007;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}
// } Driver Code Ends