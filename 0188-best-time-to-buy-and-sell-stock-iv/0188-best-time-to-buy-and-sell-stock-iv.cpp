class Solution {
public:
int n,y;
int dp[1005][5][105];
    int solve(int i,int j,int k,vector<int>& prices){
        if(i>=n) return 0;
        if(dp[i][j][k] != -1e9) return dp[i][j][k];

        int ans = 0;

        if(j==1){
            if(k<y)
            ans = max((prices[i] + solve(i+1,0,k+1,prices)),ans);
            ans = max((solve(i+1,1,k,prices)),ans);
        }else{
            if(k<y)
            ans = max((-prices[i] + solve(i+1,1,k,prices)),ans);
            ans = max((solve(i+1,0,k,prices)),ans);
        }
        return dp[i][j][k] = ans;
    }
    int maxProfit(int k, vector<int>& prices) {
         n = prices.size();
         y =k;
        for(int i =0; i<n; i++){
            for(int j =0; j<5; j++) {
                for(int z =0; z<105; z++)
                 dp[i][j][z] = -1e9;
            }
        }
        n = prices.size();

        return solve(0,0,0,prices);
    }
};