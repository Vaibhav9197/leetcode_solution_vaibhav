class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int head =-1; int tail =0;
        int n = s.length();
        int ans = 0;
        map<char,int>mp;

        while(tail<n){
            while(head+1<n && mp[s[head+1]]==0){
                head++;
                mp[s[head]]++;
            }
            ans = max(ans, head-tail+1);

            if(tail>head){
                tail = head-1;
            }
            mp[s[tail]]--;
            tail++;
        }
        return ans;
    }
};