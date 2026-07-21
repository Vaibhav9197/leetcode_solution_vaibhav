class Solution {
public:
    int dp[2005];
    int n;

    bool isPalindrome(int i,int j,string &s){
        while(i<=j){
            if(s[i]!= s[j]) return 0;
            i++,j--;
        }
        return 1;
    }
    int solve(int i,string &s) {
        if (i == n) return -1;
        if(dp[i] != -1) return dp[i];
        int ans = INT_MAX;

        for (int j = i; j < n; j++) {
            if (isPalindrome(i, j,s)) {
                ans = min(ans, 1 + solve(j + 1,s));
            }
    }

    return dp[i] = ans;
}
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        n= s.length();
        return solve(0,s);
    }
};