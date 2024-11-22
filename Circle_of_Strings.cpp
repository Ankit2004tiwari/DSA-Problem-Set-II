//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int node, vector<int> adj[], vector<bool> &visited)
    {
        visited[node] = true;
        for(auto it : adj[node])
        {
            if(!visited[it])
                dfs(it, adj, visited);
        }
    }
    int isCircle(vector<string> &arr) {
        
        vector<int> adj[26];
        vector<int> Indegree(26, 0);
        vector<int> Outdegree(26, 0);
        
        for(int i = 0; i < arr.size(); i++)
        {
            string temp = arr[i];
            
            int u = temp[0] - 'a';
            int v = temp[temp.size()-1] - 'a';
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
            Indegree[u]++;
            Outdegree[v]++;
        }
        
        for(int i = 0; i < 26; i++)
        {
            if(Indegree[i] != Outdegree[i])
                return 0;
        }
        
        int node = arr[0][0] - 'a';
        
        vector<bool> visited(26, false);
        
        dfs(node, adj, visited);
        
        for(int i = 0; i < 26; i++)
        {
            if(Outdegree[i] && !visited[i])
                return 0;
        }
        
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends