class Solution {
public:
    int dp[505][505];
    int n,m;

    int solve(int i, int j,string &word1, string &word2){
        if(i ==n && j<m){
            return m-j;
        }
        if(j ==m && i<n){
            return n-i;
        }
        if(dp[i][j] != -1) return dp[i][j];

        if(i==n&& j==m) return 0;
        int ans = 1e9;
        if(word1[i]==word2[j])
            ans = min(ans,solve(i+1,j+1,word1,word2));
        else{
            ans = min({
            1+solve(i,j+1,word1,word2), //insert
            1+solve(i+1,j,word1,word2),    //delete
            1+solve(i+1,j+1,word1,word2),    //replace
    });
        }
        return dp[i][j] = ans;
        
    }
    int minDistance(string word1, string word2) {
        n = word1.length();
        m= word2.length();

        memset(dp,-1,sizeof(dp));

        return solve(0,0,word1,word2);
    }
};