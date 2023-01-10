class Solution {
public:
    
    int maxDepth(string s) {
        int mx = 0, cnt =0;
        for(int i = 0; i <s.length(); i++){
            if(s[i] == '('){
                cnt++;
                mx = max(cnt, mx);
            }
            else if(s[i] == ')'){
                cnt--;
            }
        }
        return mx;
    }
};