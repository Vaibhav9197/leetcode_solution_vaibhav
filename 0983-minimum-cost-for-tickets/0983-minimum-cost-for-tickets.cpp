class Solution {
public:
    int n;
    int dp[365];
    int solve(int i,vector<int>& days, vector<int>& costs){
        if(i>n)return 1e9;
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];

        int ans = 1e9;
        if(dp[i]!=-1)return dp[i];

        int j1 = days[i]+1;
        int j7 = lower_bound(days.begin()+i,days.end(),days[i]+7)-days.begin();
        int j30 = lower_bound(days.begin()+i,days.end(),days[i]+30)-days.begin();
        ans = min({ans,solve(i+1,days,costs)+costs[0],solve(j7,days,costs)+costs[1],solve(j30,days,costs)+costs[2]});

        return dp[i]=ans;

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        n = days.size();
        return solve(0,days,costs);
    }
};