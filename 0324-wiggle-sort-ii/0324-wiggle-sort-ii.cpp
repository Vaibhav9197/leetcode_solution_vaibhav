class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>odd,even;
        int n = nums.size();
        for(int i =n; i>((n+1)/2); i--){
            odd.push_back(nums[i-1]);
        }
        for(int i =((n+1)/2); i>0; i--){
            even.push_back(nums[i-1]);
        }
        for(int i =0; i<odd.size(); i++){
           cout<<odd[i];
        }cout<<endl;
        for(int i =0; i<even.size(); i++){
            cout<<even[i];
        }
        int i =0,j=0,k=0;
        while(k<n){
           if(i<even.size()) nums[k] = even[i];k++;
            if(j<odd.size())nums[k] = odd[j]; 
            i++,j++,k++;
        }
    }
};