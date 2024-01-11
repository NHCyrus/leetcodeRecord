int minSubArrayLen(int target, int* nums, int numsSize) {
   if (numsSize == 0) {
       return 0;
   }
    int ans = INT_MAX;
    for (int i = 0 ; i < numsSize ; i++) {
        int sum = 0;
        for (int j = i ; j < numsSize ; j++ ) {
            sum += nums[j];
            if (sum >= target) {
                if (ans > j - i + 1) {
                    ans = j - i + 1;
                }
            }
        }
    } 
       
    return ans == INT_MAX ? 0 : ans;
}