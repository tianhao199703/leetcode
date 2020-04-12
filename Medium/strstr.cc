int strStr(string haystack, string needle) {
        if(needle.empty())return 0;
        int i=0,m=haystack.size();//文本指针i用来指示文本串
        int j=0,n=needle.size();//模式指针j用来指示模式串
        vector<int> nextVal=get_nextVal(needle);
        while(i<m&&j<n){
            if(j==-1||needle[j]==haystack[i])i++,j++;
            else j=nextVal[j];
        }
        return j==n?i-j:-1;
    }
    vector<int> get_nextVal(const string& pat){
        int n=pat.size();
        vector<int> nextVal(n,-1);//这里next数组大小为n，已经算上pat[n-1]了
        int k=-1,j=0;
        while(j<n-1){
            if(k==-1||pat[k]==pat[j]){
                k++,j++;
                if(pat[j]!=pat[k])nextVal[j]=k;
                else nextVal[j]=nextVal[k];
            }
            else k=nextVal[k];
        }
        return nextVal;
    }
