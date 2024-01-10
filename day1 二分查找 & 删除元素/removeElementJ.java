 public int removeElement(int[] nums, int val) {
      int n = nums.length;
      for (int i = 0; i < n ; i++ ) {
          if (nums[i] == val ) {
              for(int j =  i + 1; j < n ; j++ ) {
                  nums[j - 1] = nums[j];
              }
            i--;
            n--;
          }
      }
      return n;
    }