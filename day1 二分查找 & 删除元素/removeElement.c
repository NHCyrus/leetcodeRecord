int removeElement(int* nums, int numsSize, int val) {
    for (int i = 0 ; i < numsSize ; i++) {
        if (nums[i] == val) {
            for (int j = i + 1; j < numsSize ; j++) {
                nums[j - 1] = nums[j];
            }
            i--;
            numsSize--;
        }
    }
    return numsSize;
}