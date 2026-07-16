class Solution {
public:
    int dp[10005];
    int amt;
    
    int solve(int a,vector<int>& coins){
        if(a>amt) return 1e9;
        if(a==amt) return 0;
        if(dp[a] != -1) return dp[a];

        int ans = 1e9;
        for(int i =0; i<coins.size(); i++){
            if(coins[i] <= amt - a)
            ans = min(ans,1 + solve(a+coins[i],coins));
        }

        return dp[a]=ans;
    }
   
    int coinChange(vector<int>& coins, int amount) {
        amt = amount;
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,coins);
        return ans >= 1e9 ? -1 :ans;
    }
};