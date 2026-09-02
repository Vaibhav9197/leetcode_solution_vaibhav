class Solution {
public:
    void wiggleSort(vector<int>& nums) {
       int n = nums.size();
       auto mid = nums.begin() + n/2;
       nth_element(nums.begin(),mid,nums.end());

       int midv = *mid;

       int i =0,j=0,k = n-1;

       #define A(i) nums[((1+2*i)) %(n|1)]

       while(j<=k){
            if(A(j)>midv) {
                swap(A(j),A(i));
                i++,j++;
                }
            else if(A(j)<midv) {
                swap(A(j),A(k));
                k--;
                }
            else j++;
       }
    }
};