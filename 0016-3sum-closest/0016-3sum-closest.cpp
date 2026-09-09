class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int mini = INT_MAX;
        int val = 0;
        int n = nums.size();
        for(int i =0;i<n; i++){
            int j = i+1; int k = n-1;
            while(j<k){
                int sum = (nums[i]+nums[j]+nums[k]);
                if((abs(sum-target))<mini){
                   mini = (abs(sum-target));
                   val = nums[i]+nums[j]+nums[k];
                }
                
                if((nums[i]+nums[j]+nums[k]) > target) k--;
                else if((nums[i]+nums[j]+nums[k])<target) j++;
                else {
                    j++;
                    k--;
                }
            }
        }
        return val;
    }
};