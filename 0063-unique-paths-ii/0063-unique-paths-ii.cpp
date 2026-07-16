class Solution {
public:
    int dp[105][105];
    int n,m;
    int solve(int i,int j,vector<vector<int>>& obstacleGrid){
         if(i>=n || j>=m || obstacleGrid[i][j]==1)
           return 0;
        if(i==n-1 && j==m-1)return 1;
       

        if(dp[i][j] != -1) return dp[i][j];

        int ans =0;
        if(j<m && i<n && obstacleGrid[i][j]==0)
            ans = solve(i,j+1,obstacleGrid) + solve(i+1,j,obstacleGrid);

        return dp[i][j] = ans;
            
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp,-1,sizeof(dp));
        n = obstacleGrid.size();
        m = obstacleGrid[0].size();
        return solve(0,0,obstacleGrid);
    }
};