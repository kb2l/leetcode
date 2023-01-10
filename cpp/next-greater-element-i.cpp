class Solution
{

public:
    map<int, int> temp;
    
    void func(vector<int>& nums, int curr, int target)
    {
        if (curr >= nums.size())
            return;

        if (target >= nums.size())
        {
            temp[nums[curr]] = -1;
            return;
        }

        if (nums[target] > nums[curr])
        {
            auto val = nums[target];
            auto index = nums[curr];
            temp[index] = val;
        }
        else
        {
            if (temp[nums[target]] == -1) temp[nums[curr]] = -1;
            else return func(nums, curr, target + 1);
        }
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        temp[nums2[nums2.size() - 1]] = -1;
        int j = nums2.size() - 1;
        while (j > 0)
            func(nums2, j - 1, j), j--;
        vector<int> ret;

        for (auto e : nums1)
            ret.push_back(temp[e]);

        return ret;
    }
};