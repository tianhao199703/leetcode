vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty()||k==0)return {};
        vector<int> result;
        deque<int> window;
        
        for(int i=0;i<k;++i){
            //窗口不为空并且下标i表示的元素大于window尾部下标表示的元素，删除尾部下标，保证窗口的头部为最大值
            while(!window.empty()&&nums[i]>nums[window.back()])
                window.pop_back();
            window.push_back(i);//此时窗口的头部为最大值
        }
        //将第一个窗口的最大值添加到result中
        result.push_back(nums[window.front()]);
        
        for(int i=k;i<nums.size();++i){
            //窗口中的队头下标小于等于i-k表示队头下标属于上一个窗口的，需要删除，这种情况就是当前数组是倒序的时候才会发生
            if(!window.empty()&&window.front()<=i-k)
                window.pop_front();
            
            //窗口不为空并且下标i表示的元素大于window尾部下标表示的元素，删除尾部下标，保证窗口的头部为最大值，
            //此时要不是当前头部最大，要不是新的元素最大
            while(!window.empty()&&nums[i]>nums[window.back()])
                window.pop_back();
            
            window.push_back(i);//此时窗口的头部为最大值，可能为i
            result.push_back(nums[window.front()]);//将窗口的最大值添加到result中
        }
        
        return result;
    }
