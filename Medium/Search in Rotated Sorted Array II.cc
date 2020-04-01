bool search(vector<int>& nums, int target) {
        int left = 0, right =  nums.size()-1, mid;
        
        while(left<=right){
            mid = (left + right) >> 1;
            if(nums[mid] == target) return true;
            //下面这行在数组确定没有重复元素的时候可以删去，即为Search in Rotated Sorted Array I的解法
            if( (nums[left] == nums[mid]) && (nums[right] == nums[mid]) ) {++left; --right;}
            else if(nums[left] <= nums[mid]){
                if( (nums[left]<=target) && (nums[mid] > target) ) right = mid-1;
                else left = mid + 1; 
            }
            else{
                if((nums[mid] < target) &&  (nums[right] >= target) ) left = mid+1;
                else right = mid-1;
            }
        }
        return false;
    }
