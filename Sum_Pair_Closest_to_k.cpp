//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    vector<int> sumClosest(vector<int> &arr, int k)
    {
        int i = 0;
        int j = arr.size() - 1;
        int nearestSum = INT_MAX;
        vector<int> ans;
        while (i < j)
        {
            int currentSum = arr[i] + arr[j];
            if (abs(currentSum - k) < abs(nearestSum - k))
            {
                nearestSum = currentSum;
                ans = {arr[i], arr[j]};
            }
            if (currentSum < k)
                i++;
            else
                j--;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--)
    {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, k);
        cout << ans[0] << " " << ans[1] << "\n";
    }

    return 0;
}
// } Driver Code Ends