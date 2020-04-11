int calculate(string s) {
        stack<int> stack;
        int pos = 0;
        while (pos < s.size()){
            if (s[pos] == '(') stack.push(pos);
            if (s[pos] == ')'){
                int left = stack.top();
                stack.pop();
                int res = calculate_help(s.substr(left + 1, pos - left - 1));
                s = s.erase(left, pos - left + 1);
                auto newstr = to_string(res);
                s.insert(left, newstr);
                pos = left + newstr.size() - 1;
            }
            pos++;
        }
        return calculate_help(s);
    }
    int calculate_help(string s){
        istringstream in('+' + s + '+');
        long long total = 0, term = 0, n;
        char op;
        while (in >> op) {
            if (op == '+' || op == '-') {
                total += term;
                in >> term;
                if(op == '-') term *= -1;
            }
            else{
                in >> n;
                if(op == '*') term *= n;
                else term /= n;
            }
        }
        return total;
    }
