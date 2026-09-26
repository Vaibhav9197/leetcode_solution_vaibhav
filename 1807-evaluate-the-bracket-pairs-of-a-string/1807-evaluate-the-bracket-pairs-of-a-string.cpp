class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        int n = knowledge.size();
        for(int i =0; i<n; i++){
            mp[knowledge[i][0]] = knowledge[i][1]; 
        }
        int l = s.length();
        string ans="";
        for(int i=0; i<l; i++){
            if(s[i]!='('){
                ans+=s[i];
            }else {
                string key ="";
                int j =i+1;
                while(s[j]!=')'){
                    key+=s[j];
                    j++;
                }
                i=j;
                auto val = mp.find(key);
                if(val != mp.end()) ans += val->second;
                else ans +='?';

            }
        }
        return ans;
    }
};