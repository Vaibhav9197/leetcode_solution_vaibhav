class Solution {
public:
    int dp[105][105];
    int n,m;

    int solve(int i, int j,vector<vector<int>>& matrix){
        if(i>=n || j>=m || j<0) return 1e9;
        if(i==n-1) return matrix[i][j];
        if(dp[i][j] != -1e9) return dp[i][j];

        int ans = 1e9;
        ans = min(ans,matrix[i][j] + solve(i+1,j,matrix));
        ans = min(ans,matrix[i][j] + solve(i+1,j+1,matrix));
        ans = min(ans,matrix[i][j] + solve(i+1,j-1,matrix));

        return dp[i][j] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for(int i=0;i<105;i++)
            for(int j=0;j<105;j++)
                dp[i][j] = -1e9;
        n= matrix.size();
        m=matrix[0].size();

        int ans =1e9;
        for(int i = 0; i<m; i++){
            ans = min(ans,solve(0,i,matrix));
        }
        return ans;
    }
};