vector<string> generateParenthesis(int n) {
        vector<string> res;
        addingpar(res, "", n, 0);
        return res;
    }
    //n表示待匹配的左括号数，m表示已匹配的左括号还剩对应的右括号数
    void addingpar(vector<string> &v, string str, int n, int m){
        if(n==0 && m==0) 
        {
            v.push_back(str);
            return;
        }
        if(m > 0){ addingpar(v, str+")", n, m-1); }
        if(n > 0){ addingpar(v, str+"(", n-1, m+1); }
    }
