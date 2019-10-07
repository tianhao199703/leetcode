 int longestValidParentheses(string s) {
        int n = s.size(),length=0;
        stack<int> store;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') store.push(i);
            else {
                if (!store.empty()) {
                    if (s[store.top()] == '(') store.pop();
                    else store.push(i);
                }
                else store.push(i);
            }
        }
        if (store.empty()) length = n;
        else {
            int a = n, b = 0;
            while (!store.empty()) {
                b = store.top(); 
                store.pop();
                length = max(length, a-b-1);
                a = b;
            }
            length = max(length, a);
        }
        return length;
    }
