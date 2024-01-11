public int minSubArrayLen(int target, int[] nums) {
       int n = nums.length;
       if (n == 0) {
           return 0;
       }
       int head = 0 , tail = 0;
       int sum = 0;
       int ans = Integer.MAX_VALUE;
       while (tail < n ){
           sum += nums[tail];
           while (sum >= target) {
               ans = Math.min(ans, tail - head + 1);
               sum -= nums[head];
               head++;
           }
           tail++;
       }
      return ans == Integer.MAX_VALUE ? 0 : ans ;
    }