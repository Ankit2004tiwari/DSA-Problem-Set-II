//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        int i = 0;
        string str = str1;
        
        str[0] = str1[str1.size()-2];
        str[1] = str1[str1.size()-1];
        
        
        while(str1[i+2] != NULL)
            str[i+2] = str1[i], i++;
        
        if(str == str2)
            return true;
            
        i = 0;
        char temp = str1[0];
        char temp1 = str1[1];
        
        while(str1[i+2] != NULL)
        {
            str1[i] = str1[i+2];
            i++;
        }
        
        str1[i] = temp;
        str1[i+1] = temp1;
        
        if(str1 == str2)
            return true;
          
        return false;
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends