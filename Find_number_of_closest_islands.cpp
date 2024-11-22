//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    void dfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        for(int i = 0; i < 4; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                  && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
            {
                dfs(nrow, ncol, vis, grid);
            }
        }
    }
    
    int closedIslands(vector<vector<int>>& grid, int n, int m) {
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int j = 0; j < m; j++)
        {
            if(!vis[0][j] && grid[0][j] == 1)
            {
               vis[0][j] = 1;
               dfs(0, j, vis, grid); 
            }
            if(!vis[n-1][j] && grid[n-1][j] == 1)
            {
                vis[n-1][j] = 1;
                dfs(n-1, j, vis, grid);
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            if(!vis[i][0] && grid[i][0] == 1)
            {
                vis[i][0] = 1;
                dfs(i, 0, vis, grid); 
            }
            if(!vis[i][m-1] && grid[i][m-1] == 1)
            {
                vis[i][m-1] = 1;
                dfs(i, m-1, vis, grid);
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!vis[i][j] && grid[i][j] == 1)
                {
                    cnt++;
                    dfs(i, j, vis, grid);
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends