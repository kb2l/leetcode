class Solution {
public:
    const int MAX_INT = pow(2, 31) -1;

    inline bool is_number(char c) {
        return ((c <= 57) && (c >= 48));
    }

    int myAtoi(string str) 
    {
        const int L = str.length();

        int end = 0;
        if( L== 1) end = 1;
        else {
            for(end = L-1; end>=0 ; --end) {
                if(str[end] == ' ' || !is_number(str[end])) continue;
                else break;
            }
        }

        int start=0;
        for( start =0; start< L; ++start) {
            if(str[start] == ' ') continue;
            if( (str[start] != '-') && (str[start] != '+') &&  !is_number(str[start]) ) return 0;
            else break;
        }

        int signe = 1;
        if (str[start] == '-') { signe = -1; ++start;}
        else if(str[start] == '+') ++ start;
        if (start > end) return 0;
        
        int res = 0;
        int i =0;
        bool overflow = false;
        for (auto k = end; k >= start; --k)
        {
            char c = str[k];
            if (!is_number(c)) { i = 0; res = 0; continue; };
            auto d = (c - '0') * pow(10, i++);
            res += d;
            if (res < 0) overflow =true;	
        }

        if ( (res != 0) && overflow) 
        {
            if (signe > 0) 
            {
                res = MAX_INT;
            }
            else 
            {
                res =  MAX_INT + 1;
            }
        }

        return (signe * res);
    }

};