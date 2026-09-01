class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int ans=0,curend =0,far = 0;
    
        for(int i=0; i<n-1; i++){
            far = max(far,i+nums[i]);
            if(i==curend){
                ans++;
                curend = far;
            }
        }
        return ans;
    }
};