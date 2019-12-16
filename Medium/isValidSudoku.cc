bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9,vector<bool>(9,true)), col(9,vector<bool>(9,true)), box(9,vector<bool>(9,true));
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    if(!(col[i][num] && row[j][num] && box[k][num]))
                        return false;
                    col[i][num] = row[j][num] = box[k][num] = false;
                }
            }
        }
        return true;
    }
