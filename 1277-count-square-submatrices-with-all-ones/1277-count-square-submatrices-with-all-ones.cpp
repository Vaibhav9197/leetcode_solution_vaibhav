class Solution {
public:
    int dp[305][305];
    int n,m;
    int solve(int i,int j,vector<vector<int>>& matrix){
        if(i>=n || j >=m) return 0;
        if(matrix[i][j] ==0) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        int ans = 1e9;

        ans = min(1+solve(i,j+1,matrix),ans);
        ans = min(1+solve(i+1,j+1,matrix),ans);
        ans = min(1+solve(i+1,j,matrix),ans);

        return dp[i][j] = ans;

    }
    int countSquares(vector<vector<int>>& matrix) {
        memset(dp,-1,sizeof(dp));
        n = matrix.size();
        m = matrix[0].size();
        int ans =0;
        //solve(0,0,matrix);
        for(int i=0; i<n; i++){
            for(int j =0; j<m; j++){
                 ans += solve(i, j, matrix);
            }
        }

         return ans;   
    }
};