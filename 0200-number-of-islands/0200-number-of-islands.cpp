class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j,int m, int n){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0')return;
        else{
            grid[i][j]='0';
            dfs(grid,i+1,j,m,n);
            dfs(grid,i-1,j,m,n);
            dfs(grid,i,j+1,m,n);
            dfs(grid,i,j-1,m,n);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        int cnt =0;
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(grid[i][j] == '1') {
                    cnt++;
                    dfs(grid,i,j,m,n);
                    }
            }
        }
        return cnt;
    }
};