class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while (x != 0) {
            res *= 10;
            res += x%10;
            if(res > numeric_limits<int>::max() || res < numeric_limits<int>::min()) return 0;
            x /= 10;
        }
        return res;
    }
};