class Solution {
public:
    int maxArea(vector<int>& v) {
        int right = v.size() - 1;
        int left = 0;
        int _max = 0;

        while (left < right)
        {
            int curr = (right - left) * min(v[right], v[left]);
            _max = max(_max, curr);
            if (v[right] < v[left]) right--;
            else left++;
        }

        return _max;
    }
};