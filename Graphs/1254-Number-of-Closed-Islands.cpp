/*
LeetCode 1254 - Number of Closed Islands
Topic: Graphs
Approach: DFS
Time Complexity: O(M * N)
Space Complexity: O(M * N)

Where:
M = number of rows in the grid
N = number of columns in the grid
*/

/* 
    Very similar to Number of Islands
    It can be a prerequisite for this problem
*/

class Solution {
public:
    void dfs(int row,int col,int delrow[],int delcol[],vector<vector<int>>& grid,vector<vector<int>> &vis){
        vis[row][col] = 1;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0;i<4;i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol] == 0){
                dfs(nrow,ncol,delrow,delcol,grid,vis);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};
        vector<vector<int>> vis(m,vector(n,0));
        for(int i = 0;i<m;i++){
            if(!vis[i][0] && grid[i][0] == 0) dfs(i,0,delrow,delcol,grid,vis);
            if(!vis[i][n-1] && grid[i][n-1] == 0) dfs(i,n-1,delrow,delcol,grid,vis);
        }
        for(int i = 0;i<n;i++){
            if(!vis[0][i] && grid[0][i] == 0) dfs(0,i,delrow,delcol,grid,vis);
            if(!vis[m-1][i] && grid[m-1][i] == 0) dfs(m-1,i,delrow,delcol,grid,vis);
        }
        int count = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(!vis[i][j] && grid[i][j] == 0){
                    dfs(i,j,delrow,delcol,grid,vis);
                    count++;
                }
            }
        }
        return count;
    }
};
