 bool judgePoint24(vector<int>& nums) {
        vector<double> A;
        for (int v: nums) A.push_back((double) v);
        return solve(A);
    }
    bool solve(vector<double> &nums){
        if (nums.size() == 0) return false;
        if (nums.size() == 1) return fabs(nums[0] - 24) < 1e-6;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i != j) {
                    vector<double> nums2;
                    for (int k = 0; k < nums.size(); k++) if (k != i && k != j) {
                        nums2.push_back(nums[k]);
                    }
                    for (int k = 0; k < 4; k++) {
                        if (k < 2 && j > i) continue;
                        if (k == 0) nums2.push_back(nums[i] + nums[j]);
                        if (k == 1) nums2.push_back(nums[i] * nums[j]);
                        if (k == 2) nums2.push_back(nums[i] - nums[j]);
                        if (k == 3) {
                            if (nums[j] != 0) {
                                nums2.push_back(nums[i] / nums[j]);
                            } else {
                                continue;
                            }
                        }
                        if (solve(nums2)) return true;
                        nums2.pop_back();
                    }
                }
            }
        }
        return false;
    }
