//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    static bool comparator(pair<int,int> a, pair<int,int>b)
    {
        if(a.second == b.second)    return a.first > b.first;
        else return a.second > b.second;
    }
    
    vector<int> topK(vector<int>& arr, int k) {
        
        vector<int> res;
        vector<pair<int, int>> vec;
        map<int, int> mpp;
        int n = arr.size();
        
        for(auto it : arr)
            mpp[it]++;
        
        for(auto it : mpp)
            vec.push_back({it.first, it.second});
            
        sort(vec.begin(), vec.end(), comparator);
        
        for(int i = 0; i < vec.size() && i < k; i++)
            res.push_back(vec[i].first);
        
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends