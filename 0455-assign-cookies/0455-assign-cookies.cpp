class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n = g.size(), m = s.size();
        int i =0,j=0;
        int cnt =0;
        while(i<n && j <m){
            cout<<i<<" "<<j<<" "<<cnt<<endl;
             if(s[j]>=g[i]){
                cnt++;
                i++;j++;
             }else
             j++;
        }
        return cnt;
    }
};