class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total =0;
        for(int i =0; i<n; i++){
            total+=cardPoints[i];
        }
        int t = n-k;
        if(t == 0) return total;
        int head =-1, tail =0;
        int ans = 1e9;
        int sum =0;
        while(tail<=n-t){
            while(head+1 <n && head-tail+1<(n-k)){
                head++;
                sum+=cardPoints[head];
            }
            if(head-tail+1==t) ans = min(ans,sum);
            sum-=cardPoints[tail];
            tail++;
        }
        return (total - ans);
    }
};