int minimumMoves(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n,n));
        for(int i = 0;i < n; ++i){
            dp[i][i] = 1;
        }
        for(int i = 1;i < n; i++){
            for(int j = 0; j+i < n; j++){
                if(arr[j] == arr[j+i]){
                    if(i == 1){
                        dp[j][j+i] = 1;
                    }else{
                        dp[j][j+i] = dp[j+1][j+i-1];
                    }
                }else{
                    for(int k = j; k < j+i; ++k){
                        dp[j][j+i] = min(dp[j][j+i],dp[j][k]+dp[k+1][j+i]);
                    }
                }
            }
        }
        
        return dp[0][n-1];
    }
