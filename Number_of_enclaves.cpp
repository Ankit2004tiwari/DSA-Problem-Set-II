//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    void bfs(int row, int col, vector<vector<int>> &vis,
             vector<vector<int>> &grid, int delrow[], int delcol[])
    {
        int n = grid.size();
        int m = grid[0].size();
        
        vis[row][col] = 1;
        queue<pair<int, int>>q;
        q.push({row, col});
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++)
            {
               int nrow = r + delrow[i];
               int ncol = c + delcol[i]; 
               if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                  && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int j = 0; j < m; j++)
        {
            if(!vis[0][j] && grid[0][j] == 1)
            {
                vis[0][j] = 1;
                bfs(0, j, vis, grid, delrow, delcol);
            }
            if(!vis[n-1][j] && grid[n-1][j] == 1)
            {
                vis[n-1][j] = 1;
                bfs(n-1, j, vis, grid, delrow, delcol);
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            if(!vis[i][0] && grid[i][0] == 1)
            {
                vis[i][0] = 1;
                bfs(i, 0, vis, grid, delrow, delcol);
            }
            if(!vis[i][m-1] && grid[i][m-1] == 1)
            {
                vis[i][m-1] = 1;
                bfs(i, m-1, vis, grid, delrow, delcol);
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1 && !vis[i][j])   cnt++;
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends