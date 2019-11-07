vector<int> singleNumber(vector<int>& nums) {
        int r = 0, n = nums.size(), i = 0, last = 0;
        vector<int> ret(2, 0);
        
        for (i = 0; i < n; ++i) 
            r ^= nums[i];
        
        last = r & (~(r - 1));//这一步是为了获得最右边的1的位置
        for (i = 0; i < n; ++i)
        {
            if ((last & nums[i]) != 0)
                ret[0] ^= nums[i];
            else
                ret[1] ^= nums[i];
        }
        
        return ret;
    }
