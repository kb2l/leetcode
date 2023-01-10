class Solution {
public:
    bool isprime(int n){
        if (n < 2) return false;
        for (int x = 2; x*x <= n; x++){	
            if (n%x == 0) return false;
        }
        return true;
    }
    
    int primePalindrome(int N) {
        if (8 <= N && N <= 11) return 11;
        for (int x = 1; x < 100000; x++){
            string s = to_string(x), r(s.begin(), s.end());
            string subs = r.substr(0, r.size() - 1);
            reverse(subs.begin(), subs.end());
            int y = stoi(s + subs);
            if (y >= N && isprime(y)) {
                return y;
            }
	    }
        return -1;
    }
};