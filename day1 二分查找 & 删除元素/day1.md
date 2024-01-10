# day1 数组

## 二分查找

> 题目链接：[二分查找](https://leetcode.cn/problems/binary-search/description/)

###  题目描述

> 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。



### 解题思路

设置两个指针，一个指向数组头部，一个指向数组尾部。指向数组头部的不断向后遍历数组，指向数组尾部的不断向前遍历数组。直到遍历到target位为止

注意head , tail指针的取值问题，如果遇到只有一个元素的数组则更加需要注意取值。

### 实现代码

**C**

```` c
int search(int* nums, int numsSize, int target) {
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
````

***

**Java**

````java
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
````

Java已经提供了二分查找的方法binarySearch(Object[] a, Object key)[^1]



## 移除元素

> 题目链接: [移除元素](https://leetcode.cn/problems/remove-element/description/)

### 题目描述

> 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
>
> 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
>
> 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。



### 解题思路

> 快慢指针 快指针用来指向覆盖的元素 , 慢指针用来指向被覆盖的元素



**C**

````c
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
````



***

**Java**

````java
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
````















***



[^1]:  public static int binarySearch(Object[] a, Object key)
用二分查找算法在给定数组中搜索给定值的对象(Byte,Int,double等)。数组在调用前必须排序好的。如果查找值包含在数组中，则返回搜索键的索引；否则返回 (-(插入点) - 1)。
