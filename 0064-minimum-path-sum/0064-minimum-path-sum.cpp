class Solution {
public:
    int dp[205][205];
    int n,m;

    int solve(int i, int j,vector<vector<int>>& grid){
        if(i>=n || j >=m) return 1e9;
        if(i==n-1 && j==m-1) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 1e9;
        ans = min(ans,grid[i][j] + solve(i+1,j,grid));
        ans = min(ans,grid[i][j] + solve(i,j+1,grid));

        return dp[i][j] = ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        n = grid.size();
        m = grid[0].size();
        return solve(0,0,grid);
    }
};