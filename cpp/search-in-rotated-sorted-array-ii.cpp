class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0) return false;
        if(nums.size() == 1) {
            if( nums[0] == target) return true;
            return false;
        }
        
        int last = nums.size() -1;
        if(target == nums[last] || target == nums[0]) return true;
        
        if(target>nums[last]) {
            while(last >0 && nums[last] < target) last--;
            if(nums[last] == target) return true;
            
            auto it = lower_bound(nums.begin(), nums.begin() + last, target);
            if(it != nums.end()  && *it  == target) return true;
            
            return false;
        }
        
        int begin  = 0;
        if(target<nums[last]) {
            while(begin < last && nums[begin] > target) begin++;
            if(nums[begin] == target) return true;
            
            auto it = lower_bound(nums.begin() + begin, nums.end(), target);
            
            if(it != nums.end() && *it  == target) return true;
            
            return false;
        }
        return false;    
    }
};