class Solution {
public:
int dp[5005];int n;
    int solve(int i,vector<int>& nums){
        if(i<2)return 0;
        if(dp[i] != -1) return dp[i];

        if(nums[i]-nums[i-1] == nums[i-1]-nums[i-2])
            return dp[i] = 1+ solve(i-1,nums);
        
        return dp[i] = 0;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        n = nums.size();
        if(n<3)return 0;
        int ans =0;
        for(int j =2; j<n; j++){
            ans= ans+solve(j,nums);
        }
        return ans;
    }
};