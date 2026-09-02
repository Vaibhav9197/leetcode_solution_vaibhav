class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int n = points.size();
        long long last =LLONG_MIN,ans=0;
        long long f =LLONG_MIN;
        for(int i=0; i<n; i++){
            int st = points[i][0];
            int end = points[i][1]; 
            if( st<=last ){
                f = max(f,(long long)f);
                last = min((long long)end,last);
                continue;
            }else{
                ans++;
                f = points[i][0];
                last = points[i][1];
            }
        }
        return ans;
    }
};