int maxCoins(vector<int>& nums) {
        int N = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> d(N+2,vector<int>(N+2,0));
        for(int c = 1;c <= N;++c){
            for(int i = 1;i+c-1 <= N;++i){
                const int j = i+c-1;
                int& ans=d[i][j];
                for(int k=i;k<=j;++k){
                    ans=max(ans,nums[i-1]*nums[k]*nums[j+1]+d[i][k-1]+d[k+1][j]);
                }
            }
        }
        return d[1][N];
    }
