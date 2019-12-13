 int longestValidParentheses(string s) {
        int n=s.size();
        stack<int> pos;
        for(int i=0;i<n;i++){
            if(s[i] == ')' && !pos.empty() && s[pos.top()] == '(') pos.pop();
            else pos.push(i);
        }
        int a = n,length = 0,b;
        while(!pos.empty()){
            b = pos.top();
            pos.pop();
            length = max(length,a-b-1);
            a = b;
        }
        return max(length,a);
    }
