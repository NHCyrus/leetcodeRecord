int search(int* nums, int numsSize, int target) {
        //定义头尾指针
        int head , tail;
        head =  0;  tail = numsSize - 1;
        while (head <= numsSize / 2 || tail >= numsSize / 2 ) {
            if (nums[head] == target) {
                return head;
            }
            if (nums[tail] == target) {
                return tail;
            }
            head++;
            tail--;
        }
        return -1;
    
}