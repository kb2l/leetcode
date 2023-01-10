class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<string, int> m1;
        unordered_map<string, int> m2;
        for(int i = 0; i < s.length(); i++){
            string e;e+= s[i];
            m1[e]++;
            m2[e] = i;
        }
        int mi = 1e5;
        for(auto it = m1.begin(); it != m1.end(); ++it){
            if(it->second == 1) mi = min(mi, m2[it->first]);
        }
        if(mi == 1e5) return -1;
        return mi;
    }
};