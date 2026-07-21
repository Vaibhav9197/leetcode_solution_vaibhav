class Solution {
public:
    int dp[2005];
    int n;
    int pali[2005][2005];

    bool isPalindrome(int i,int j,string &s){
        if(i>=j) return 1;
       if(s[i]!= s[j]) return 0;
       if(pali[i][j]!= -1) return pali[i][j];

       
            return pali[i][j] = isPalindrome(i+1,j-1,s);
       
       
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
        memset(pali,-1,sizeof(pali));
        isPalindrome(0,n-1,s);
        n= s.length();
        return solve(0,s);
    }
};