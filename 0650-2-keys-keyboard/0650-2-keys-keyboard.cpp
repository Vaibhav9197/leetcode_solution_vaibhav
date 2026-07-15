class Solution {
public:
    int dp[1005][1005];
    int N;
    int solve(int i,int j){
        if(i==N)return 0;
        if(i>N) return 1e9;

        if(dp[i][j]!= -1)return dp[i][j];

        int ans =INT_MAX;
        if(i!=j) ans = min(ans,1+solve(i,i));
        if (j > 0) ans = min(ans,1+solve(i+j,j));

        return dp[i][j] = ans;
    }
    int minSteps(int n) {
        N =n;
        memset(dp,-1,sizeof(dp));
        return solve(1,0);
    }
};