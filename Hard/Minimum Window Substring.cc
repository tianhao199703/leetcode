   string minWindow(string s, string t) {
        if (s.empty() || t.empty()){return "";}
        int count = t.size(),n=s.size();
        unordered_map<char,int> require;
        //用一个hashmap记录字符串T中的字符类别，也可以用一个128位的数组代替
        for (int i = 0; i < count; ++i){
            if(require.find(t[i])!=require.end()){
                require[t[i]]++;
            }
            else{require[t[i]]=1;}
        }
        int i = -1,j = 0,minLen = INT_MAX,minIdx = 0;
        while (i < n && j < n){
            if (count){//s中还没有匹配到一个合适的子字符串
                i++;
                if(require.find(s[i])!=require.end()){
                    require[s[i]]--;
                    if(require[s[i]] >= 0) {count--;}
                }
            }
            else{
                if (minLen > i - j + 1){//记录当前最小长度，更新存储变量
                    minLen = i - j + 1;
                    minIdx = j;
                }
                if(require.find(s[j])!=require.end()){//移动j，直到该子字符串中不能完全包含t。
                    require[s[j]]++;
                    if(require[s[j]] > 0) {count++;}
                }
                j++;
            }
        }
        if (minLen == INT_MAX){return "";}
        return s.substr(minIdx, minLen);
    }
