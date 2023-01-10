class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto start = find(nums.begin(), nums.end(), target);
        auto end = find(nums.rbegin(), nums.rend(), target);
        if(start == nums.end() || end == nums.rend()) return {-1, -1};
        int begin = std::distance(nums.begin(), start);
        int rbegin = std::distance(nums.rbegin(), end);
        return {begin, static_cast<int>(nums.size() - rbegin -1)};
    }
};