//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int upper_bound(vector<long long> arr, long long x)
    {
        int res = 0;
        int low = 0; 
        int high = arr.size()-1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(arr[mid] <= x)
            {
                res = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return arr[res] == x ? res : -1;
    }
    int lower_bound(vector<long long> arr, long long x)
    {
        int res = 0;
        int low = 0; 
        int high = arr.size()-1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(arr[mid] < x)
            {
                low = mid+1;
            }
            else 
            {
                res = mid;
                high = mid-1;
            }
        }
        return arr[res] == x ? res : -1;
    }
    
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        int i = upper_bound(v, x);
        int j = lower_bound(v, x);
        return {j, i};
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends