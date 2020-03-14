int findMinStep(string board, string hand) {
        unordered_map<char,int> store;
        for(int i=0;i<hand.size();i++){
            if(store.find(hand[i])!=store.end()){store[hand[i]]++;}
            else{store[hand[i]] = 1;}
        }
        return dfs(board,store);
    }
    int dfs(string board,unordered_map<char,int> store){
            if(board.empty()) return 0;
            int res = INT_MAX, i = 0,j;
            while(i<board.size()){
                j=i+1;
                while (j<board.size() and board[i]==board[j]) j++;
                int need = 3-(j-i);
                if (store[board[i]]>=need){
                    need = max(0,need); //为了解决已经有的连接的球，并且球数可能大于3个
                    store[board[i]] -= need;
                    int temp = dfs(board.substr(0,i)+board.substr(j),store);
                    if (temp>=0){
                        res = min(res,need+temp);
                    }    
                    store[board[i]] += need;
                }    
                i=j;
            }
            if(res == INT_MAX) return -1;
            else return res;
    }
