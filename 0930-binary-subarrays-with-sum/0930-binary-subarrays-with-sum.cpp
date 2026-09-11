class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int head =-1; int tail =0;
        int trail =0;
        int ans =0; int sum =0;

        while(tail<n){
            while(head+1<n && (sum<goal || nums[head+1]==0)){
                head++;
                if(nums[head]==1)trail =0;
                else trail++;
                sum+=nums[head];
            }
            if(sum==goal) ans+=min(trail,head-tail)+1;
            if(nums[tail]==1)sum--;
            tail++;
        }
        return ans;
    }
};