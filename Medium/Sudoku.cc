class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] != '.'){
                    int num = board[i][j]-'0'-1, k = i/3*3+j/3;
                    if(!(row[i][num] && col[j][num] && box[k][num])) return;
                    row[i][num] = col[j][num] = box[k][num] = false;
                }
            }
        }
        //上面的部分是判断试读是否是valid的代码
        backtrack(board, 0, 0);   
    }
    bool backtrack(vector<vector<char>> &board,int i,int j){
        if (i==9) return true;
        if (j==9) return backtrack(board, i+1, 0);
        if (board[i][j] != '.') return backtrack(board, i, j+1);
        for (char ch = '1'; ch <= '9'; ch++) {
            int num = ch-'0'-1;
            if (row[i][num] && col[j][num] && box[i/3*3+j/3][num]){
                board[i][j] = ch;
                row[i][num] = col[j][num] = box[i/3*3+j/3][num] = false;
                if(backtrack(board, i, j + 1)){return true;}
                board[i][j] = '.';
                row[i][num] = col[j][num] = box[i/3*3+j/3][num] = true;
            }
        }
        return false;
    }
private:
    vector<vector<bool>> row=vector(9,vector<bool>(9,true));
    vector<vector<bool>> col=vector(9,vector<bool>(9,true));
    vector<vector<bool>> box=vector(9,vector<bool>(9,true));
};
