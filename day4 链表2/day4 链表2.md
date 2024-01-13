# day4 链表2

## 两两交换链表中的节点

> 题目链接: [两两交换题目中的节点](https://leetcode.cn/problems/swap-nodes-in-pairs/)

### 题目描述

给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

 ### 解题思路

申请两个虚拟节点，第一个虚拟节点cur用来记录当前需要进行的交换的第一个节点，next用来记录下一次需要进行交换的第一个节点。

***

**C**

````c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* cur = head;
    struct ListNode* next = NULL;
    if (cur == NULL) {
        return cur;
    }
    while (cur->next!= NULL) {
        next = cur->next->next;
        int temp = cur->next->val;
        cur->next->val = cur->val;
        cur->val = temp;
        cur = next;
        if (next == NULL) {
            break;
        }
        
    }
    return head;

    
}
````

***

**Java**

````java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode cur = head , next = null;
        if (cur == null) {
            return head;
        }
        while (cur.next != null) {
            next = cur.next.next;
            int temp = cur.next.val;
            cur.next.val = cur.val;
            cur.val = temp;
            if (next == null) {
                break;
            }
            cur = next;
        }
        return head;
    } 
}
````

***

## 删除链表的倒数第N个节点  

> 题目链接 [删除链表的倒数第N个节点  ]()

### 题目描述

给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

***

### 解题思路

快慢指针，快指针比满指针多走n步，当快指针走到最后一个元素时慢指针就处在倒数第n个元素上。

**C**

````C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* temp = malloc(sizeof (struct ListNode));
    temp->val = 0;
    temp->next = head;
    struct ListNode* quick = head;
    struct ListNode* slow = temp;
    for (int i = 0; i < n ; i++) {
        quick = quick->next;
    }
    while(quick != NULL) {
        quick = quick->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    head = temp->next;
    free(temp);
    
     return head;
     
}
````



***

**Java**

````java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode temp = new ListNode(0);
        temp.next = head;
        ListNode quick = head;
        ListNode slow = temp;
        for (int i = 0; i < n ; i++) {
            quick = quick.next;
        }
        while (quick != null) {
            quick = quick.next;
            slow = slow.next;
        }
        slow.next = slow.next.next;
        head = temp.next;
        return head;
    }
}
````

***

## 链表相交

> 题目链接： [链表相交](https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/description/)

### 题目描述

给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。

### 解题思路

如果两个链表相交了，那么相交的节点到最后一个节点的长度是相同的

**C**

````c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* cura = headA;
    struct ListNode* curb = headB;
    int lena = 0, lenb = 0 , gap = 0;
    while (cura != NULL) {
        lena++;
        cura = cura->next;
    }
    while (curb != NULL) {
        lenb++;
        curb = curb->next;
    }
    cura = headA;
    curb = headB;
    if (lena > lenb ) {
        gap = lena - lenb;
        while (gap--) {
            cura = cura->next;
        }
        while (cura) {
            if (cura == curb) {
                return cura;
            }
            cura = cura->next;
            curb = curb->next;
        }
    } else {
        gap = lenb - lena;
        while (gap--) {
            curb = curb -> next;
        }
        while (curb) {
            if (cura == curb ){
                return cura;
            }
            cura = cura->next;
            curb = curb->next;
        }
    }
    return NULL;
}
````



***

**Java**

````java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode cura = headA , curb = headB;
        int lena = 0 ,lenb = 0 , gap = 0;
        while (cura != null) {
            lena++;
            cura = cura.next;
        }
        while (curb != null) {
            lenb++;
            curb = curb.next;
        }
        cura = headA;
        curb = headB;
        if (lena > lenb) {
            gap = lena - lenb;
            while (gap-- != 0){
                cura = cura.next;
            }
            while (cura != null) {
                if (cura == curb) {
                    return cura;
                }
                cura = cura.next;
                curb = curb.next;
            }
        } else {
            gap = lenb - lena;
            while (gap-- != 0) {
                curb = curb.next;
            }
            while (curb != null) {
                if (cura == curb) {
                    return cura;
                }
                cura = cura.next;
                curb = curb.next;
            }
        }
        return null;
    }
}
````

***

## 环形链表

> 题目链接： [环形链表](https://leetcode.cn/problems/linked-list-cycle-ii/description/)

***

### 题目描述

给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

不允许修改 链表。

### 解题思路

定义快慢指针，快指针的移动速度是慢指针的两倍（这样可以确保一定会在环里相遇）

**C**

````c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow ){
            struct ListNode* index1 = fast;
            struct ListNode* index2 = head;
            while (index1 != index2) {
                index1 = index1->next;
                index2 = index2->next;
            }
            return index1;
        }
        
    }
    return NULL;
    
}
````

***

**Java**

````java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;
        
        while (fast != null && fast.next != null ){
            fast = fast.next.next;
            slow = slow.next;
            if (fast == slow ) {
                ListNode index1 = fast;
                ListNode index2 = head;
                while (index1 != index2) {
                    index1 = index1.next;
                    index2 = index2.next;
                }
                return index1;
            }
        }
        return null;
    }
}
````

