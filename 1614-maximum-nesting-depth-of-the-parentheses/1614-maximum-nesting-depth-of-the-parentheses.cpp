class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int ans =0;int depth = INT_MIN;
        for(int i =0; i<n; i++){
            if(s[i]=='('){
                ans++;
            }else if(s[i]==')')ans--;
            depth = max(depth,ans);
        }
        return depth;
    }
};