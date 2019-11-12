int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> record{{0,1}};
        int cursum=0,count=0,n=nums.size();
        for(int i=0;i<n;i++){
            cursum += nums[i];
            if(record.find(cursum-k)!=record.end()){
                count += record[cursum-k];
            }
            record[cursum]++;
        }
        return count;
    }

