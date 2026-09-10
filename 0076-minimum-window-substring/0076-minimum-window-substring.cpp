class Solution {
public:
    string minWindow(string s, string t) {
        int head = -1; int tail =0;
        int bestlen = INT_MAX; int beststrt = 0;
        int n = s.length(); int m = t.length();
        int need[128] = {0}; int mp[128]= {0};

        for(auto &x : t) need[(unsigned char)x]++;
        int missing =m;

        while(tail<n){
            while(head+1<n  && missing>0){
                mp[(unsigned char)s[++head]]++;
                if(mp[(unsigned char)s[head]] <= need[(unsigned char)s[head]]) missing--;
            }
            if(missing >0)break;

            if(head-tail+1 < bestlen){
                bestlen = head-tail+1;
                beststrt = tail;
            }
            mp[(unsigned char)s[tail]]--;
            if(mp[(unsigned char)s[tail]]<need[(unsigned char)s[tail]])missing++;
            tail++;
        }
        return (bestlen==INT_MAX?"" :s.substr(beststrt,bestlen));
    }
};