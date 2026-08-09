/*
LeetCode 200 - Number of Islands
Topic: Graphs, DFS

Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/

class Solution {
    void dfs(int row,int col,int delrow[],int delcol[],vector<vector<char>>& grid,vector<vector<int>> &vis){
        vis[row][col] = 1;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0;i<4;i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];
            if(nrow>= 0 && nrow<m && ncol>= 0 && ncol<n && !vis[nrow][ncol]&&grid[nrow][ncol] == '1'){
                dfs(nrow,ncol,delrow,delcol,grid,vis);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(m,vector<int> (n,0));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    dfs(i,j,delrow,delcol,grid,vis);
                    count++;
                }
            }
        }
        return count;
    }
};
