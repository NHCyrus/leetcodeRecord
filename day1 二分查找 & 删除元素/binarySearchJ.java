 public int search(int[] nums, int target) {
        int head , tail;
        head = 0; tail = nums.length - 1;
        while ( head <= nums.length / 2 || tail >= nums.length / 2 ) {
            if (nums[head] == target ){
                return head;
            }
            if (nums[tail] == target){
                return tail;
            }
            head++;
            tail--;
        }
        return -1;
    }