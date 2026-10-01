class Solution {
public:
    int dp[21][5001];
    int neg = -1e9; int n;
    int solve(int i, int d,vector<int>& rods){
        if(i==n) return (d==0?0 : neg);

        if(dp[i][d]!=INT_MIN) return dp[i][d];
        
        int r = rods[i];
        int skip = solve(i+1,d,rods);
        int addlonger = solve(i+1,d+r,rods);

        int addshort;
        if(d<=r){
            addshort = d+solve(i+1,r-d,rods);
        }else{
            addshort = r+solve(i+1,d-r,rods);
        }
        return dp[i][d] = max({skip,addlonger,addshort});
    }
    int tallestBillboard(vector<int>& rods) {
        n = rods.size();
        for(int i =0; i<21; i++){
            for(int j =0; j<5001; j++){
                dp[i][j] = INT_MIN;
            }
        }
        return max(0,solve(0,0,rods));
    }
};