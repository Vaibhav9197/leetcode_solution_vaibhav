class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
            int head =-1; int tail =0;
            int zero =0;
            int ans =0;
            int n = nums.size();

            while(tail<n){
                while(head+1 <n && (zero <k || nums[head+1]==1)){
                    head++;
                    if(nums[head]==0)zero++;
                    else continue;
                }
                ans = max(ans,head-tail+1);
                
                if(tail>head){
                    tail++;
                    head = tail -1;
                    zero =0;
                }         
                else {
                    if(nums[tail]==0){
                        zero--;
                        }
                        tail++;
                }
            }
            return ans;
    }
};