//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void Reverse(int arr[], int start, int end)
    {
        while(start < end)
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
    vector<int> nextPermutation(vector<int> &arr){
        // code here
        int n = arr.size();
        int ind = -1;
        
        for(int i = n - 2; i >= 0; i--)
        {
            if(arr[i] < arr[i+1])
            {
                ind = i;
                break;
            }
        }
        if(ind == -1)
        {
            Reverse(arr.data(), 0, (n - 1));
        }
        else 
        {
            for(int i = n - 1; i > ind; i--)
            {
                if(arr[ind] < arr[i])
                {
                    swap(arr[i], arr[ind]);
                    break;
                }
            }
            Reverse(arr.data(), (ind+1), (n - 1));
        }
        return arr;
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
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends