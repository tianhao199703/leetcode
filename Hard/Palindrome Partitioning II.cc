int minCut(string s) {
        int n = s.size();
        vector<int> cut(n+1,0);
        for (int i = 0; i <= n; i++) cut[i] = i-1;//对于长度为N的字符串，最多可以切N-1刀来达到目的。
        for (int i = 0; i < n; i++) {
            for (int j = 0; i-j >= 0 && i+j < n && s[i-j]==s[i+j] ; j++)//针对奇数型回文序列
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j]);
            for (int j = 1; i-j+1 >= 0 && i+j < n && s[i-j+1] == s[i+j]; j++)//针对偶数型的回文序列
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j+1]);
        }
        return cut[n];
    }
