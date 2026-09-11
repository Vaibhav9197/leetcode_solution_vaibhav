class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int mp[5]={0}; int size =0;
        int head = -1; int tail =0;
        int ans =0;

        while(tail<n){
            while(head+1<n && (size <3)){
                if(mp[s[head+1]-'a']==0)size++;
                mp[s[++head]-'a']++;
            }
            if(size ==3)ans+=(n-head);
            mp[s[tail]-'a']--;
            if(mp[s[tail]-'a']==0){
                size--;
            }
            tail++;
        }
        return ans;
    }
};