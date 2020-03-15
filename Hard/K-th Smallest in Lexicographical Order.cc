int findKthNumber(int n, int k) {
        int cur=1;
        --k;
        while(k>0){
            long long first=cur,last=cur+1,step=0;
            while(first<=n){//查找节点之间有几个节点
                step+=min((long long)n+1,last)-first;
                first*=10;
                last*=10;
            }
            if(step<=k){//说明不在cur这个子树下，cur++找下一个子树
                k-=step;
                cur++;
            }else{//进入cur的子树寻找
                k--;
                cur*=10;
            }
        }
        return cur;
    }
