class Solution {
public:
    int strStr(string haystack, string needle) {
         if (needle.empty() || haystack.empty())
            return -1;

        char c = needle[0];
        auto res = haystack.find(needle);
        if (res != string::npos)
            return res;

        return -1;
    }
};