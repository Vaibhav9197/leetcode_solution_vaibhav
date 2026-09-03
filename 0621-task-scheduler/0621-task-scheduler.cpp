class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> mp;
        for (auto &x : tasks) mp[x]++;
        priority_queue<int> pq;
        int total = 0;
        for (auto &x : mp) pq.push(x.second);
        while (!pq.empty()) {
            vector<int> v;
            for (int i = 0; i <= n; i++) {
                if (pq.empty()) break;
                v.push_back(pq.top());
                pq.pop();
            }
            for (int i = 0; i < v.size(); i++)
                if (v[i] - 1 > 0) pq.push(v[i] - 1);
            total += pq.empty() ? v.size() : n + 1;
        }
        return total;
    }
};