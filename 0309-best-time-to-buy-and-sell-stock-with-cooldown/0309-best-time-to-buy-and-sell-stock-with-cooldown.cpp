class Solution {
public:
    int dp[5005][2];
    int n;
    int solve(int i, int j,vector<int>& prices){
        if(i>=n) return 0;
        if(dp[i][j] != -1e9) return dp[i][j];

        int ans = INT_MIN;
        if(j){
            ans = max(ans,prices[i] + solve(i+2,0,prices));    
            ans = max(ans, solve(i+1,1,prices));
        }else{
            ans = max(ans,-prices[i] + solve(i+1,1,prices));    
            ans = max(ans, solve(i+1,0,prices));   
        }
        return dp[i][j] = ans;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        for(int i =0; i<n; i++){
            for(int j =0; j<2; j++)dp[i][j]=-1e9;
        }
        return solve(0,0,prices);
    }
};