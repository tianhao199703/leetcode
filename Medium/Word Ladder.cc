    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int length=INT_MAX;
        if(distance(beginWord,endWord)==0){return 1;}
        if(find(wordList.begin(),wordList.end(),endWord)==wordList.end()){return 0;}
        unordered_set<string> wordDict;
        for(auto &i:wordList){wordDict.insert(i);}
        unordered_set<string> head, tail, *phead, *ptail;
        head.insert(beginWord);
        tail.insert(endWord);
        int dist = 2;
        while (!head.empty() && !tail.empty()) {
            if (head.size() < tail.size()) {
                phead = &head;
                ptail = &tail;
            }
            else {
                phead = &tail; 
                ptail = &head;
            }
            unordered_set<string> temp; 
            for (auto itr = phead -> begin(); itr != phead -> end(); itr++) {
                string word = *itr;
                wordDict.erase(word);
                for (int p = 0; p < (int)word.length(); p++) {
                    char letter = word[p];
                    for (int k = 0; k < 26; k++) {
                        word[p] = 'a' + k;
                        if (ptail -> find(word) != ptail -> end())
                            return dist;
                        if (wordDict.find(word) != wordDict.end()) {
                            temp.insert(word);
                            wordDict.erase(word);
                        }
                    }
                    word[p] = letter;
                }
            }
            dist++;
            swap(*phead, temp);
        }
        return 0; 
    }
    int distance(string a,string b){
        int dist=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]){dist++;}
        }
        return dist;
    }
