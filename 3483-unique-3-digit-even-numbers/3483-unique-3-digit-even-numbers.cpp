class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        set<vector<int>>st;
        vector<pair<int,int>>even;
        for(int i =0; i<n; i++){
            if(digits[i]%2 ==0)even.push_back({digits[i],i});
        }
        for(int i =0;i<n;i++){
            if(digits[i]==0)continue;
            for(int j =0;j<n; j++){
                if(j==i)continue;
                for(auto &it:even){
                    if(i==it.second || j== it.second)continue;
                    st.insert({digits[i],digits[j],it.first});
                }
            }
        }
        for(auto x:st){
            cout<<x[0]<<x[1]<<x[2]<<endl;
        }
        return st.size();
    }
};