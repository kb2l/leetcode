#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>
class Solution {
public:
    bool find132pattern(vector<int>& v) {
        multiset<int> s;
            int s3 = std::numeric_limits<int>::max();
            auto n = v.size();
            for (int i = 1; i < n; i++) s.insert(v[i]);
            for (int k = 1; k < n - 1; k++) {
                auto itr = s.find(v[k]);
                if (itr != s.end()) s.erase(itr);
                auto c = v[k];
                if (s3 > v[k - 1]) s3 = v[k - 1];
                if (s3 >= c) continue;
                auto ret = s.upper_bound(s3);
                if (ret != s.end() && *ret < c) return true;
            }
            return false;
    }
};