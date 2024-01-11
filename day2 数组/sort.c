int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    (*returnSize) = numsSize;
    int* ans = malloc(sizeof(int) * numsSize);

    for (int head = 0 , tail = numsSize - 1 , pos = numsSize - 1; head <= tail ; ) {
        if (nums[head] * nums[head] > nums[tail] * nums[tail]) {
            ans[pos] = nums[head] * nums[head];
            head++;
        } else {
            ans[pos] = nums[tail] * nums[tail];
            tail--;
        }
        pos--;
    }
    return ans;
   
}