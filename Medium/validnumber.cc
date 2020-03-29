bool isNumber(string s) {
        while(s[0]==' ')  s.erase(0,1);
        if(s.size()==0) return false;
        while(s[s.size()-1]==' ') s.erase(s.size()-1, 1);
        int state = 0, n = s.size();
        bool flag = false;
        for(int i=0;i<n;i++){
            if(s[i] <= '9' && s[i] >= '0'){
                flag = true;
                switch(state){
                    case 0:
                    case 1:
                    case 2:
                        state = 2;
                        break;
                    case 3:
                    case 7:
                        state = 7;
                        break;
                    case 4:
                    case 5:
                    case 6:
                        state = 6;
                        break;
                }
            }
            else if(s[i] == '.'){
                switch(state){
                    case 0:
                    case 1:
                    case 2:
                        state = 3;
                        break;
                    default:
                        return false;
                }
            }
            else if(s[i] == 'e' || s[i] == 'E'){
                if(!flag) return false;
                switch(state){
                    case 2:
                    case 3:
                    case 7:
                        state = 4;
                        break;
                    default:
                        return false;
                }
            }
            else if(s[i] == '+' || s[i] == '-'){
                switch(state){
                    case 0:
                        state = 1;
                        break;
                    case 4:
                        state = 5;
                        break;
                    default:
                        return false;
                }
            }
            else {return false;}
        }
        return (state == 2 || (flag && state == 3) || state == 6 || state == 7);
    }
