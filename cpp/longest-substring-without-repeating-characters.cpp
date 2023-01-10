class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        if(s.length() == 1) return 1;
        int max_ = 1;
        string curr; curr += s[0];
        for (int right = 1; right < s.length(); right++)
        {
            char cand = s[right];
            size_t pos = curr.find(cand);
            curr += cand;
            if (pos == string::npos)
                max_ = max(max_, (int)curr.length());
            else
                curr = curr.substr(1 + pos);
        }
        return max_;
    }
};