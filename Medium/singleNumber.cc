int singleNumber(vector<int>& nums) {
        int x1 = 0, x2 = 0, mask = 0;
     
    for (int i : nums) {
        x2 ^= x1 & i;
        x1 ^= i;
        mask = ~(x1 & x2);
        x2 &= mask;
        x1 &= mask;
    }

	// 因为p = 1，二进制形式为 p = '01'，所以p1 = 1，所以应该返回x1。
	// 如果p = 2，二进制形式为 p = '10'，所以p2 = 1，所以应该返回x2。
	// 或者直接返回(x1 | x2)。
    return x1; 
    }
