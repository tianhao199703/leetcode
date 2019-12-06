double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(),n2=nums2.size();
        if (n1 > n2){ return findMedianSortedArrays(nums2,nums1);}
        int imin=0, imax=n1, half_len=(n1+n2+1)/2,i,j;
        int max_of_left,min_of_right;
        while (imin <= imax){
            i = (imax + imin)/2;
            j = half_len - i;
            if (i < n1 && nums2[j-1] > nums1[i])
                imin = i + 1;
            else if (i > 0 && nums1[i-1] > nums2[j])
                imax = i - 1;
            else{
                max_of_left = max(i==0?INT_MIN:nums1[i-1], j==0?INT_MIN:nums2[j-1]);

                if((n1 + n2) % 2 == 1) //odd
                    return max_of_left;
                //even
                min_of_right = min(i==n1?INT_MAX:nums1[i], j==n2?INT_MAX:nums2[j]);
                return (max_of_left + min_of_right) / 2.0;
            }
               
        }
        return 0;
    }
