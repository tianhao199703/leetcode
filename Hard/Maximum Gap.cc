//时间复杂度 O(2N+K) 空间复杂度O(3K)
int maximumGap(vector<int>& nums) {
        int size = nums.size(), maxV, minV;
        int bucket_size, bucket_num, bucket_id;
        int maxGap = INT_MIN, last_max;
        if(size<2){return 0;}
        minV = maxV = nums[0];
        //找出最大最小元
        for(int i=0;i<size;i++){
            if(minV > nums[i]) minV = nums[i];
            else if(maxV < nums[i]) maxV = nums[i];
        }
        //完成桶，同中最大最小元素的储存
        bucket_size = max(1, ((maxV-minV)/(size-1)));
        bucket_num = (maxV-minV)/bucket_size + 1;
        if(bucket_num<=1) return maxV-minV;
        vector<int> bucket_max(bucket_num, INT_MIN);
        vector<int> bucket_min(bucket_num, INT_MAX);
        vector<int> bucket_count(bucket_num, 0);
        for(int i=0; i<size; i++){
            bucket_id = (nums[i] - minV)/bucket_size;
            bucket_count[bucket_id]++;
            //储存每个桶里面的最大最小值
            bucket_min[bucket_id] = bucket_min[bucket_id] > nums[i]? nums[i]:bucket_min[bucket_id];
            bucket_max[bucket_id] = bucket_max[bucket_id] < nums[i]? nums[i]:bucket_max[bucket_id];
        }
        //因为最大gap有下界，只需要在桶与桶之间找gap
        last_max = minV;
        for(int i=0; i<bucket_num; i++){
            if(bucket_count[i]>0){
                maxGap = max(maxGap, bucket_min[i]- last_max);
                last_max = bucket_max[i];
            }
        }
        return maxGap;
    }
