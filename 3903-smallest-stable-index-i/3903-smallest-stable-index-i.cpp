class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int mini = 1e9;
        int maxi = -1e9;
        int n = nums.size();
        vector<int>v(n,0);
        for(int i =n-1; i>=0; i--){
            mini = min(nums[i],mini);
            v[i] = mini;
        }
        int st = INT_MAX;
        int idx =-1;
        for(int i =0; i<n; i++){
            maxi = max(maxi,nums[i]);
            cout<<maxi<<" "<<v[i]<<" ";
            if((maxi-v[i])<=k){
                if((maxi-v[i]) < st) return i;
            }
            st = maxi-v[i];
        }
        return idx;
    }
};