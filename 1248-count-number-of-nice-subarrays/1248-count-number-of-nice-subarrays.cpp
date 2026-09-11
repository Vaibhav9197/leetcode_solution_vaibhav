class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int head = -1, tail =0;
        int ans =0; int odd =0;int trails =0;

        while(tail<n){
            while(head+1<n && (odd<k || nums[head+1]%2==0 )){
                if(nums[++head]%2){odd++; trails =0;}
                else trails++;
            }
           if(odd == k) ans+= trails+1;

            if(nums[tail]%2)odd--;
            tail++;
        }
        return ans;
    }
};