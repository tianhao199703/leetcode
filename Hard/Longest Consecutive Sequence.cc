int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> numbers;
        int length = 0;
        for (int i : nums) {
            if (numbers[i]) {continue;}
            length = max(length, numbers[i]=numbers[i+numbers[i+1]]=numbers[i-numbers[i-1]]=numbers[i+1]+numbers[i-1]+1);
        }//这个地方就是维护数组中连续的两端的节点和长度
        return length;
    }
