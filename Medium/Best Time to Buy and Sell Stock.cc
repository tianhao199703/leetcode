// 121 k=1; 122 k= infinity; 123 k = 2; 188 k = any
int maxProfit(int k, vector<int>& prices) {
        if(prices.size()<2)
            return 0;
        //称下面这部分为代码1
        if(k>prices.size()/2){
        	int maxProfit=0;
            for(int i=1; i<prices.size(); i++)
                maxProfit += max(prices[i]-prices[i-1], 0);
            return maxProfit;
        }
        //称下面这部分为代码2
        vector<int> hold(k+1,INT_MAX),rele(k+1,0);
        for(int i=0; i<prices.size(); i++){
            for(int j=1; j<=k; j++){
                hold[j] = min(hold[j], prices[i]-rele[j-1]);
                rele[j] = max(rele[j], prices[i]-hold[j]);
            }
        }
        return rele[k];
    }
 // 309 between each trans stands one cooldown.
 // 714 charge fees for each trans.
