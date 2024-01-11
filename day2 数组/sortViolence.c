int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    (*returnSize) = numsSize;
    int* ans = malloc(sizeof(int) * numsSize);

    for(int i = 0; i < numsSize  ; i++) {
        ans[i] = nums[i] * nums[i];
    }
    for (int i = 0; i < numsSize ; i++) {
        int min = i;
        for (int j = i + 1; j < numsSize ; j++) {
            if (ans[min] > ans[j]) {
                min = j;
            }
        } 
        int temp = ans[i];
        ans[i] = ans[min];
        ans[min] = temp;
    }
    return ans;
    
}