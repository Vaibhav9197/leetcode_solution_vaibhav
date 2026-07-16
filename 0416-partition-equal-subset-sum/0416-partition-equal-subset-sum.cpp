class Solution {
public:
    int dp[205][20005];
    int n;int sum;

    int solve(int i,int j,vector<int>& nums){
        if(i>=n) return j == sum -j;
        if(dp[i][j] != -1)return dp[i][j];

        int ans = 0;
        ans |= solve(i+1,j,nums);
        ans |= solve(i+1,j+nums[i],nums);

        return dp[i][j] = ans;  
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        for(int i =0; i<n; i++){
            sum+= nums[i];
        }
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,0,nums);
        return ans;
    }
};