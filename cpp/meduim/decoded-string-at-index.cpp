class Solution {
public:
    string decodeAtIndex(string S, int K) {
       long size = 0;
        for(int i =0; i < S.size(); i++){
            if(isalpha(S[i]))size++;
            if(isdigit(S[i])) size *= S[i] - '0';
        }
        int N  = S.size();
        for(int i = N -1; i>= 0; i--){
            K %= size;
            if(K == 0 && isalpha(S[i])) return (string) "" + S[i];
            
            if(isalpha(S[i])) size--;
            if(isdigit(S[i])) size /= (S[i] - '0');
        }
        return "";
            
    }
    
};