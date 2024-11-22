//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string reverse(string ans)
    {
        string res = "";
        int j = ans.size()-1;
        
        while(ans[j] == '0')  j--;
        for(int i = j; i >= 0; i--)  res += ans[i];
        
        return res;
    }
    string minSum(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        string str1 = "";
        string str2 = "";
        for(int i = 0; i < arr.size(); i++)
        {
            if(i % 2 == 0)
                str1 += to_string(arr[i]);
            else str2 += to_string(arr[i]);
        }
        
        int i = str1.size()-1;
        int j = str2.size()-1;
        string ans = "";
        
        int add = 0, carry = 0;
        
        while(j != -1) 
        {
            int num1 = str1[i--] - '0'; 
            int num2 = str2[j--] - '0'; 
            add = num1 + num2;
            if(add > 9)
            {
                add += carry;
                ans += to_string(add % 10);
                carry = 1;
            }
            else 
            {
                add += carry;
                if(add > 9) carry = 1;
                else carry = 0;
                ans += to_string(add % 10);
            }
        }
        if(i != -1)
        {
            int num1 = str1[i--] - '0'; 
            ans += to_string(num1+carry);
            carry = 0;
        }
        if(carry != 0)
            ans += to_string(carry);
        return reverse(ans);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends 