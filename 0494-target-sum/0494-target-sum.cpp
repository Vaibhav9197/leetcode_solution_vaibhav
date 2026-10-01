class Solution {
public:
    int dp[21][2002];
    int n;

    int solve(int i , int sum,vector<int>& nums, int target){
        if(i==n)return (sum==target ? 1 :0);
       // if(sum == target)return 1;
        if(dp[i][sum]!= 1001)return dp[i][sum];

       return (dp[i][sum] = solve(i+1,sum+nums[i],nums,target)
        + solve(i+1, sum-nums[i],nums,target));
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        for(int i =0; i<21; i++){
            for(int j =0; j<2002; j++){
                dp[i][j] = 1001;
            }
        }
        return solve(0,1001,nums,target+1001);
    }
};