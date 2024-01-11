# day2

***

##  1.有序数组的平方

> 题目链接: [有序数组的平方](https://leetcode.cn/problems/squares-of-a-sorted-array/)

### 题目描述

给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

### 解题思路

#### 个人思路 

先平方数组后用选择排序来解决。（时间复杂度为O(n^2^)）

**C**

```` c
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
````

***

**Java**

````Java
 public int[] sortedSquares(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            nums[i] = nums[i] * nums[i];
        }
        for (int i = 0; i < nums.length; i++) {
            int min = i;
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[min] > nums[j]) {
                    min = j;
                }
            }
            int temp = nums[i];
            nums[i] = nums[min];
            nums[min] = temp;
        }
        return nums;
    }
````

> 注：该题目进阶版要求时间复杂度为O(n) 因此下列解法为时间复杂度为O(n)的解法

**C**

````C
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
````

***

**Java**

````java
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
````

***

## 长度最小的子数组

> 题目链接: [长度最小的子数组](https://leetcode.cn/problems/minimum-size-subarray-sum/)

### 题目描述

给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其总和大于等于 target 的长度最小的 连续子数组 [nums~l~, nums~l+1~, ..., nums~r-1~, nums~r~] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

### 解题思路

1.暴力求解

**C**

````c
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
````

***

**Java**

````java
 public int minSubArrayLen(int target, int[] nums) {
       int n = nums.length;
       if (n == 0) {
           return 0;
       }
        int ans = Integer.MAX_VALUE;
        for (int i = 0 ; i < n ; i++ ){
            int sum = 0;
            for(int j = i ; j < n ; j++) {
                sum += nums[j];
                if (sum >= target) {
                    ans = Math.min(ans, j - i + 1);
                    break;
                }
            }
        }
      return ans == Integer.MAX_VALUE ? 0 : ans ;
    }
````



2.滑动窗口

**C**

````c
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
````

***



**Java**

````java
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
````



***

### 螺旋矩阵

> 题目链接: [螺旋矩阵](https://leetcode.cn/problems/spiral-matrix-ii/)

#### 题目描述

给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

#### 解题思路

整个过程可以拆解为4部分 ，y不动从左到右进行填充，x不动从上到下进行填充，y不动从右到左进行填充，x不动从下上到填充

#### 解法

**C**

````c
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    
    int** ans = malloc(n * sizeof(int*));
    *returnSize = n;
    *returnColumnSizes = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        ans[i] = malloc(n * sizeof(int));
        memset(ans[i] , 0 , siezeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }

    int up = 0, down = n - 1, left = 0, right = n - 1, num = 1;
    while(1) {
        for (int j = left ; j <= right ; j++ ) {
            ans[up][j] = num++;
        } 
        if(++up > down) {
            break;
        }
        for (int i = up ; i <= down ; i++ ) {
            ans[right][i] = num++;
        }
        if (--right < left) {
            break;
        }
        for (int j = right ; j >= left ; j++ ) {
            ans[down][j] = num++;
        }
        if (--down < up) {
            break;
        }
        for (int i = down ; i >= up ; i++ ) {
            ans[left][i] = num++;
        }
        if (++left > right) {
            break;
        }
    }

    return ans;

    
}
````



> 理论上应该可以完成 但是leetcode报了奇怪的错误

***

**Java**

````java
  public int[][] generateMatrix(int n) {
        int ans[][] = new int[n][n];
        int up = 0 , down = n -1 , left = 0 , right = n -1 , num = 1;
        while (true) {
            for (int j = left ; j <= right ; j++ ) {
                ans[up][j] = num++;
            }
            if (++up > down) {
                break;
            }
            for (int i = up; i <= down; i++) {
                ans[i][right] = num++;
            }
            if (--right < left) {
                break;
            }
            for (int j = right ; j >= left ; j--) {
                ans[down][j] = num++;
            }
            if (--down < up) {
                break;
            }
            for (int i = down ; i >= up ; i-- ) {
                ans[i][left] = num++;
            }
            if (++left > right) {
                break;
            }
        }
        return ans;
    }
````



