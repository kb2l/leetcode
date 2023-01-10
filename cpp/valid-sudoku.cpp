class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0 ; i < board.size(); i++){
            set<char> m;
            for(int j =0; j < board.size(); j++){
                if(board[i][j] != '.' && m.find(board[i][j]) != m.end()){
                    return false;
                }
                m.insert(board[i][j]);
            }
        }
        
        for(int i = 0 ; i < board.size(); i++){
            set<char> m;
            for(int j =0; j < board.size(); j++){
                if(board[j][i] != '.' && m.find(board[j][i]) != m.end()){
                    return false;
                }
                m.insert(board[j][i]);
            }
        }
        
        int counter   = 0;
        set<char> ma;
        for(int col = 0 ; col < board.size(); col= col+3){
                for(int row = 0; row < board.size() * 3; row++) {
                    int i=  row/3;
                    int j = row%3 + col;
                    
                    if(board[i][j] != '.' && ma.find(board[i][j]) != ma.end())
                        return false;
                    ma.insert(board[i][j]);
                    
                    if(counter == 8) {
                        counter = 0;
                        ma.clear();
                    }
                    else counter++;
                }
            }
        return true;
    }
};