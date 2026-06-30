class Solution {
public:
    int numberOfSubstrings(string s) {
        int count[3] = {0,0,0};int result =0; int i =0; int n = s.length();
        for(int j =0; j<n; j++){
            ++count[s[j]-'a'];
            while(count[0] && count[1] && count[2]) --count[s[i++]-'a'];
            result+=i;
        }
        return result;
    }
};