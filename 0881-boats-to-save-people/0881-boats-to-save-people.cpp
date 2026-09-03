class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        multiset<int>st;
        int n = people.size();
        int boat =0;
        for(int i =0; i<n; i++){
            st.insert(people[i]);
        }
        while(!st.empty()){
            int x = *st.begin();
            int y = limit - x;
            st.erase(st.find(x));
            auto it = st.upper_bound(y);
            if((it != st.begin()) && (*(--it))+x <= limit){
                    st.erase(it);
                }
            boat++;
        }
        return boat;
    }
};