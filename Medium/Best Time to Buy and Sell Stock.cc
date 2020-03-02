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
        vector<int> hold(k+1,INT_MIN),rele(k+1,0);
        for(int i=0; i<prices.size(); i++){
            for(int j=1; j<=k; j++){
                hold[j] = max(hold[j], rele[j-1]-prices[i]);
                rele[j] = max(rele[j], prices[i]+hold[j]);
            }
        }
        return rele[k];
    }
 // 309 between each trans stands one cooldown.
int n = prices.size();
        if(n<2) return 0;
        int hold=INT_MIN,rele=0,rele_pre=0;
        for(int i=0; i<n; i++){
            int tmp = rele;
            hold = max(hold, rele_pre-prices[i]);//rele_pre表示这次出售需要隔一天
            rele = max(rele, prices[i]+hold);
            rele_pre = tmp;
        }
        return rele;
 // 714 charge fees for each trans.
int n = prices.size();
        if(n<2) return 0;
        int hold=INT_MIN,rele=0;
        for(int i=0; i<n; i++){
            hold = max(hold, rele-prices[i]);
            rele = max(rele, prices[i]+hold-fee);
        }
        return rele;

