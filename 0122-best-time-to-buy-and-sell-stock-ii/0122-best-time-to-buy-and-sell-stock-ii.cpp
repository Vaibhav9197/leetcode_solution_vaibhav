class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i =0, j= 1;
        int ans =0;
        int n = prices.size();
        while(j<n){
            if(prices[j]>prices[i]){
                ans += (prices[j]-prices[i]);
                cout<<ans<<" ";
            }j++,i++;
        }
        return ans;
    }
};