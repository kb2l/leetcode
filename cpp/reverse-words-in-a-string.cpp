class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                if(temp.size()) {
                    st.push(temp);
                    temp = "";
                }
            }
            else {
                temp+= s[i];
            }
        }
        if(temp.size()) st.push(temp);
        string ret;
        if(st.size()) {ret+= st.top(); st.pop();}
        while(st.size()) {
            ret+= " "; ret+= st.top(); st.pop();
            
        }
        return ret;
    }
};