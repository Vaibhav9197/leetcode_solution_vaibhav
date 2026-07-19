class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2;
        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        vector<vector<int>>L(n+1), R(n+1);

        for(int mask =0; mask<(1<<n); mask++){
                int cnt = 0;
                int sumL = 0;
                int sumR = 0;
            for(int j =0; j<n; j++){
                if(mask & (1<<j)){
                    cnt++;
                    sumL += left[j];
                    sumR += right[j];
                }
            }
             L[cnt].push_back(sumL);
             R[cnt].push_back(sumR);
        }
        int total =0;
        for(int i =0; i<2*n; i++){
            total+= nums[i];
        }
       for (int i = 0; i <= n; i++)
            sort(R[i].begin(), R[i].end());

        int ans = 1e9;

        for(int i =0; i<=n; i++){
           for(auto x : L[i]){
                int target = (total/2)-x;
                auto &v = R[n-i];
                auto it = lower_bound(v.begin(),v.end(),target);

                if(it != v.end()){
                    int s = x + *it;
                    ans = min(ans,abs(total-2*s));
                } 
                if(it != v.begin()){
                    it--;
                    int s = x + *it;
                    ans = min(ans,abs(total-2*s));
                } 
           }
        }
        return ans;
    }
};