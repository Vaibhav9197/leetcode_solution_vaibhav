class Solution {
public:
int dp[50];
    int solve(int i,int n){
        if(i==n)return 1;
        if(i>n) return 0;
        if(dp[i]!= -1) return dp[i];
        int ans =0;
       // ans = max(ans , solve(i+1,n));
       
        ans = solve(i+1,n) + solve(i+2,n);
        return dp[i] = ans;
    }
    int climbStairs(int n) {
       memset(dp,-1,sizeof(dp));
       return solve(0,n);
    }
};