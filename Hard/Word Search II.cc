//Trie树代码见https://github.com/tianhao199703/algorithm/blob/master/Tree/Trie.cc
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie(words);
        TrieNode* root=trie.getRoot();
        int m = board.size(),n = board[0].size();
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                findWords(board, i, j, root, "");
        vector<string> result;
        for(auto it:result_set) result.push_back(it);
        return result; 
    }
    void findWords(vector<vector<char>>& board, int i, int j, TrieNode* root, string word){
        if(i<0||i>=board.size()||j<0||j>=board[0].size() || board[i][j]==' ') return;
        
        if(root->children[board[i][j]-'a'] != nullptr){
            word += board[i][j];
            root = root->children[board[i][j]-'a']; 
            if(root->is_end) result_set.insert(word);
            char c = board[i][j];
            board[i][j]=' ';//backtrack
            findWords(board, i+1, j, root, word);
            findWords(board, i-1, j, root, word);
            findWords(board, i, j+1, root, word);
            findWords(board, i, j-1, root, word);
            board[i][j] = c;        
        }
    }
private:
    set<string> result_set;
};
