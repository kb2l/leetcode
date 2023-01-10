class Solution {
public:
    vector<int> m_nums;
    vector<int> m_bkp;
    Solution(vector<int>& nums) {
        m_nums = nums;
        m_bkp = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return m_bkp;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        next_permutation(m_nums.begin(), m_nums.end());
        return m_nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */