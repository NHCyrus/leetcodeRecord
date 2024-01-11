   public int[] sortedSquares(int[] nums) {
       int n = nums.length;
        int temp[] = new int[n];
        for (int i = 0 , tail = n - 1 , pos = n -1; i <= tail ;) {
            if (nums[i] * nums[i] > nums[tail] * nums[tail]) {
                temp[pos] = nums[i] * nums[i];
                ++i;
            } else {
                temp[pos] = nums[tail] * nums[tail];
                --tail;
            }
            --pos;
        }
        return temp;
    }