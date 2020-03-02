public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto &i:wordDict){wordD.insert(i);}
        memo[s.size()] = {""};
        return dp(s,0);
    }
    vector<string> dp(string s, int i){
        if (memo.find(i) == memo.end()){
            for(int j=i+1; j<=s.size();j++){
                if (wordD.find(s.substr(i, j-i)) != wordD.end()){
                    auto res = dp(s,j);
                    for(auto tail: res){
                        memo[i].push_back(s.substr(i, j-i) + (tail==""?"":' '+tail));//对应起点的字符串存储下来
                    }
                }
            }
        }
        return memo[i];
    }
private:
    unordered_map<int, vector<string>> memo;
    unordered_set<string> wordD;
