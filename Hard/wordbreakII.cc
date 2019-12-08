vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordD;
        for(auto &i:wordDict){wordD.insert(i);}
        unordered_map<int, vector<string>> memo {{s.size(), {""}}};
        function<vector<string>(int)> sentences = [&](int i) {
            if (!memo.count(i))
                for (int j=i+1; j<=s.size(); j++)
                    if (wordD.count(s.substr(i, j-i)))
                        for (string tail : sentences(j))
                            memo[i].push_back(s.substr(i, j-i) + (tail=="" ? "" : ' ' + tail));
            return memo[i];
        };
        return sentences(0);
    }
