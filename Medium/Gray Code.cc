vector<int> grayCode(int n) {
        vector<int> res{0};
        int cur_size,pow=1;
        for(int i=0;i<n;i++){
            cur_size = res.size();
            for(int j=cur_size-1;j>=0;j--){
                res.push_back(res[j]+pow);
            }
            pow<<=1;
        }
        return res;
    }
