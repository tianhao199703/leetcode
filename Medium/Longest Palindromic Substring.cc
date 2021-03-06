  string longestPalindrome(string s) {
        if (s.empty()) return "";
        if (s.size() == 1) return s;
        int min_start = 0, max_len = 1;
        for (int i = 0; i < s.size();) {
          if (s.size() - i <= max_len / 2) break;
          int left = i, right = i;
          while (right < s.size()-1 && s[right+1] == s[right]) ++right; // 一定可以构成回文的重复元素序列
          i = right+1;//下一次起始位置
          while (right < s.size()-1 && left > 0 && s[right + 1] == s[left - 1]) { ++right; --left; } // 向两边扩展
          int new_len = right - left + 1;
          if (new_len > max_len) { min_start = j; max_len = new_len; }
        }
        return s.substr(min_start, max_len);
    }
//另一种用dp的方法，效率低一些，但是万能
string longestPalindrome(string s) {
        int len = s.size();
        if (len < 2) return s;
        int curmax = 0;
        string curstr = "";
        vector<vector<bool>> checkPalindrome(len,vector<bool>(len,false));
        for (int right = 0; right < len; right++) {
            for (int left = 0; left <= right; left++) {
                if (s[left] == s[right] && (right - left <= 2 || checkPalindrome[left + 1][right - 1])) {
                    checkPalindrome[left][right] = true;
                    if(right-left+1 > curmax){
                        curmax = right-left+1;
                        curstr = s.substr(left,right-left+1);
                    }
                }
            }
        }
        return curstr;
    }
