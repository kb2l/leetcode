class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int size = nums.size();
        if(k == size) return;
        k = k % size;
        
        nums.resize(nums.size() * 2);
        for(int i = 0; i < size - k; i++){
            nums[size + i] = nums[i];    
        }
        nums = vector(nums.begin() + size - k, nums.begin() + 2 * size -k);
    }
};