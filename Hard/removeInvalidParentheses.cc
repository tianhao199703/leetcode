public:
vector<string> removeInvalidParentheses(string s) {
        string curr = "";
        int open = 0;
        int close = 0;
        
        int idx = 0;
        vector<string> results;
        helper(idx, curr, open, close, s);
        
        for (string r : res) results.push_back(r);
        return results;
    }
private:
    int maxLen = 0;
    unordered_set<string> res;
    void helper(int idx, string& curr, int open, int close, const string& s){
        if (idx == s.size()){//reach to the end of s
            if (open != close) return;
            if (curr.size() > maxLen){//ensure to remove mimimum number
                maxLen = curr.size();
                res.clear();
            }
            if (curr.size() == maxLen){
                res.insert(curr);    
            }
            return;
        }
        int currChar = s[idx];
        if (currChar != '(' && currChar != ')'){
            curr.push_back(currChar);
            helper(idx+1, curr, open, close, s);
            curr.pop_back();
        } 
        else{
            if (currChar == ')'){
                if (close >= open) {
                    helper(idx+1, curr, open, close, s);
                } 
                else {
                    curr.push_back(currChar);
                    helper(idx+1, curr, open, close+1, s);
                    curr.pop_back();
                    helper(idx+1, curr, open, close, s);
                }
            } 
            else {
                curr.push_back(currChar);
                helper(idx+1, curr, open+1, close, s);
                curr.pop_back();
                helper(idx+1, curr, open, close, s);
            }
        }
    }
