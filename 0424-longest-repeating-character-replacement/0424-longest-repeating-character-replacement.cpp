class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int>mp;
        int head=-1, tail =0;
        int n = s.length();
        int maxi = INT_MIN;
        int ans =0;
        while(tail<n){
            while(head+1<n && head+2-tail - max(maxi,mp[s[head+1]]+1) <=k){
                head++;
                mp[s[head]]++;
                maxi = max(maxi, mp[s[head]]);
            }
            ans = max(ans,head-tail+1);
            mp[s[tail]]--;
            tail++;
            if(head < tail-1) head = tail-1;
        }
        return ans;
    }
};