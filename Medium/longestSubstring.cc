int longestSubstring(string s, int k) {
   int max_len = 0;
   for (int first = 0; first+k <= s.size();) {
       int count[26] = {0};//每次记录字符出现次数
       int mask = 0;
       int max_last = first;
       for (int last = first; last < s.size(); ++last) {
           int i = s[last] - 'a';
           count[i]++;
           if (count[i]<k) mask |= (1 << i);//记录当前子串中包含哪些字符
           else   mask &= (~(1 << i));//如果一个字符在当前子串中已经够了k个时，将它从mask中去除
           
           if (mask == 0) {//找到一个符合要求的子串
               max_len = max(max_len, last-first+1);
               max_last = last;//当前子串的末尾位置，如果之后没有变化，说明被截断了，之后不需要考虑这部分
           }
       }
       first = max_last + 1;//从新的截断处出发
   }
   return max_len;
}
