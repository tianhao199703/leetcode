void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = m ? board[0].size() : 0;
        for (int i=0; i<m; i++) 
        {
            for (int j=0; j<n; j++) 
            {
                int count = 0;
                for (int I=max(i-1, 0); I<min(i+2, m); I++)
                    for (int J=max(j-1, 0); J<min(j+2, n); J++)
                    {
                        if(i==I&&j==J){continue;}
                        count += board[I][J] & 1;
                    }                        
                if ((board[i][j] & 1)==0)
                {
                    if(count==3) {board[i][j]=2;}
                    else{board[i][j]=0;}
                }
                else
                {
                    if(count==3||count==2) {board[i][j]=3;}
                    else{board[i][j]=1;}
                }
            }
        }
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                board[i][j] >>= 1;
    }
