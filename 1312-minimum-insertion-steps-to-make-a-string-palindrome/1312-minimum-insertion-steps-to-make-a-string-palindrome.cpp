class Solution {
public:
    int dp[505][505];
    int n;

    int solve(int i, int j, string &s){
        if(i>=j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 1e9;
        if(s[i] == s[j]) ans = min(ans,solve(i+1,j-1,s));
        else if(s[i]!=s[j]){
            ans = min(ans,1+solve(i+1,j,s));
            ans = min(ans,1+solve(i,j-1,s));
        }
        return dp[i][j] = ans;
        
    }
    int minInsertions(string s) {
        int n= s.length();
        memset(dp,-1,sizeof(dp));
        return solve(0,n-1,s);
    }
};