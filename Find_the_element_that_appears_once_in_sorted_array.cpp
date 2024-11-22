//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
 public:   
    int Search(int arr[], int left, int right)  
    {  
        if (left > right) return -1;  
    
        int mid = (left + right) / 2;   
     
        if ((arr[mid] != arr[mid - 1]) && (arr[mid] != arr[mid + 1]))  
            return arr[mid];  
            
        if(Search(arr, left, mid-1) != -1)
            return Search(arr, left, mid-1);
        return Search(arr, mid+1, right);
    }  
    
    int findOnce(int arr[], int n)  
    {  
        if (n == 1) return arr[0];  
        return Search(arr, 0, n - 1);  
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends