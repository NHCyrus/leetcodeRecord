int minSubArrayLen(int target, int* nums, int numsSize) {
   if (numsSize == 0) {
       return 0;
   }
    int ans = INT_MAX;
    int head = 0 , tail = 0;
    int sum = 0 ;
    while (tail < numsSize) {
        sum += nums[tail];
        while(sum >= target) {
            if (ans >= tail - head + 1) {
                ans = tail - head + 1;
            }
            sum -= nums[head];
            head++;
        }
        tail++;
    }
       
    return ans == INT_MAX ? 0 : ans;
}