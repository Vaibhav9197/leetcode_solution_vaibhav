class Solution {
public:
    int dp[105][2];int n;
    int solve(int i,vector<int>& nums,int prev){
        if(i==n)return 0;
        if(dp[i][prev]!= -1) return dp[i][prev];
        
        int ans =0;
        ans = max(ans,solve(i+1,nums,0));
        if(prev==0)
        ans = max(ans,nums[i]+ solve(i+1,nums,1));

        return dp[i][prev]=ans;
    }
    
    int rob(vector<int>& nums) {
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,nums,0);
    }
};