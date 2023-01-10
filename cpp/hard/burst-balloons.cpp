class Solution {
public:
  
    int seen[500][500];
    int func(vector<int> &v, int left, int right) {
        if(left +1 == right) return 0;
        if (seen[left][right] != 0) return seen[left][right];
        int ans = 0;
        for (auto index = left +1; index < right; ++index) {
            ans = max(ans, v[left] * v[right] * v[index]  + func(v, left, index) + func(v, index, right));
        }
        seen[left][right] = ans;
        return ans;
    }

    int maxCoins(vector<int>& nums) {
        vector<int> v1(nums.size() + 2);
        v1[0] = 1;
        int n = 1;
        for (auto i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) v1[n++] = nums[i];
        }
        v1[n++] = 1;
        auto res = func(v1, 0, n-1);
        //cout << res << endl;
        return res;
    }
};