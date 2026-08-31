class Solution {
public:
    int A=0,B=0,C=0;
    int dp[20][80][40][40];
    int v[7][3] = {
    {0,0,0},   // 0 — unused, placeholder so v[nums[i]] indexes directly
    {0,0,0},   // 1
    {1,0,0},   // 2
    {0,1,0},   // 3
    {2,0,0},   // 4
    {0,0,1},   // 5
    {1,1,0}    // 6
};
int n;

    int solve(int i, int a, int b, int c,vector<int>& nums){
       if (i==n) return (a==A+38 && b==B+19 && c==C+19)? 1 :0;

        if(dp[i][a][b][c]!=-1) return dp[i][a][b][c];
        int ans =0;

        ans += solve(i+1, a, b, c,nums);
        ans += solve(i+1, a + v[nums[i]][0], b + v[nums[i]][1], c + v[nums[i]][2],nums);
        ans += solve(i+1, a - v[nums[i]][0], b - v[nums[i]][1], c - v[nums[i]][2],nums);

        return dp[i][a][b][c] = ans;
    }
    int countSequences(vector<int>& nums, long long k) {
        n = nums.size();
        while(k%2 == 0){
            A++;
            k/=2;
        };
        while(k%3 == 0){
            B++;
            k/=3;
        }
        while(k%5 == 0){
            C++;
            k/=5;
        }
        if(k!=1) return 0;
        memset(dp,-1,sizeof(dp));
        return solve(0, 38, 19, 19,nums);
    }
};