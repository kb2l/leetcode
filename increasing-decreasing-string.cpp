class Solution {
public:
    string sortString(string str) {
        map<char, int> m;
        for(auto e : str){
            m[e]+= 1;
        }
        
        int itr = 0;
        string ret;
        while(itr < str.size()) {
            for(auto iter= m.begin(); iter != m.end(); iter++) {
                if(iter->second > 0) {
                    ret +=(char)iter->first;
                    iter->second--;
                    itr++;
                }
            } 

            for(auto iter= m.rbegin(); iter != m.rend(); iter++) {
                if(iter->second > 0) {
                    ret+= (char)iter->first ;
                    iter->second--;
                    itr++;
                }
            }
        }
        return ret;
    }
    
};