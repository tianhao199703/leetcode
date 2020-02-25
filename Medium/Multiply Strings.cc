string multiply(string num1, string num2) {
        string sum(num1.size() + num2.size(), '0');
        int n1 = num1.size(),n2=num2.size();
        for (int i=n1-1; i>=0; i--) {
            int carry = 0;
            for (int j=n2-1; j>=0; j--) {
                int tmp = (sum[i+j+1]-'0') + (num1[i]-'0') * (num2[j]-'0') + carry;
            sum[i+j+1] = tmp%10+'0';
            carry = tmp/10;
            }
            sum[i] += carry;
        }
    
        auto startpos = sum.find_first_not_of("0");
        if (string::npos != startpos) {
            return sum.substr(startpos);
        }
        return "0";
    }
