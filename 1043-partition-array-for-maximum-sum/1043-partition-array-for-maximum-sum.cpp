class Solution {
public:

    int dp[505];
    int n;
    int solve(int i,vector<int>& arr, int k){
        if(i>n) return 0;

        if(dp[i] != -1) return dp[i];
        int ans = 0;
        int mx = INT_MIN;
        for(int j =i; j<min(n,i+k); j++){
            mx = max(mx,arr[j]);
            ans = max(mx*(j-i+1) + solve(j+1,arr,k), ans);   
        }
        return dp[i] = ans;

    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        n = arr.size();
        return solve(0,arr,k);
    }
};