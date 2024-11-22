//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {  
public:  
    int minRepeats(string s1, string s2) {  
        string temp = s1; 
        int cnt = 1;
        
        
        if (s1 == s2) return cnt;  
        
        if(s1.length() >= s2.length())
        {
            s1 += s1;
            cnt++;
            if (s2.find(s1) == string::npos) return cnt;
        }
        
        if (s2.find(s1) == string::npos) return -1;  

        while (s1.length() < s2.length()) 
        {  
            s1 += temp;    
            cnt++;  
        }  

        if (s1.find(s2) != string::npos) return cnt;  

        s1 += temp; 
        cnt++;  
        if (s1.find(s2) != string::npos) return cnt;  

        return -1;   
    }  
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
}
// } Driver Code Ends