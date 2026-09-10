class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int head =-1; int tail =0;
        int n = s.length();
        int ans = 0;
        int mp[128]={0};

        while(tail<n){
            while(head+1<n && mp[(unsigned char)s[head+1]]==0){
                head++;
                mp[(unsigned char)s[head]]++;
            }
            ans = max(ans, head-tail+1);

            if(tail>head){
                tail = head-1;
            }
            mp[(unsigned char)s[tail]]--;
            tail++;
        }
        return ans;
    }
};