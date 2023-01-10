class Solution {
public:
    string convertToBase7(int num) {
        if(num ==0) return "0";
        bool neg = false;
        if(num < 0) neg = true, num = -num;
        
        stack<int> s;
        while(num != 0){
            auto a = num % 7;
            s.push(a);
            auto b = (num - a) / 7;    
            num = b;
        }
        string ret;
        while(!s.empty()){
            ret+= std::to_string(s.top());  
            s.pop();
        } 
        
        if(neg) {
            string ret2 = "-";
            ret2 += ret;
            return ret2;
        }
        
        return ret;
    }
};