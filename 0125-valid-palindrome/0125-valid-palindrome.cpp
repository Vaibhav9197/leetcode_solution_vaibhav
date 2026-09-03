class Solution {
public:
    bool isPalindrome(string s) {
        int i =0; int j= s.size()-1;
        while(i<j){
            s[i] = tolower(s[i]);
            s[j] = tolower(s[j]);
            if(s[i]==s[j]){
                i++,j--;
            }
            else if(!isalnum(s[i])) i++;
            else if(!isalnum(s[j])) j--;
            else return false;
        }
        return true;
    }
};