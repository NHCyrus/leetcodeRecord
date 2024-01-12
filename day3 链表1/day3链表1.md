### day3 链表1

***

#### 移除链表元素

> 题目链接: [移除链表元素](https://leetcode.cn/problems/remove-linked-list-elements/description/)

#### 题目描述

给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。



#### 解题思路

先判断头节点元素是否为要求的值，如果是将其覆盖，如果不是进入下一步。 循环遍历是防止整个数组皆是所要求的数字。

判断数组是否已经被删除干净。 申请一个虚拟头节点，方便进行操作。查询到符合要求的值时将其覆盖。

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
struct ListNode* removeElements(struct ListNode* head, int val) {
    while (head != NULL && head->val == val) {
        head = head->next;
    }
    if (head == NULL ) {
        return head;
    }
    struct ListNode* prev = head;
    while (prev->next != NULL ) {
        if (prev->next->val == val ) {
            prev->next = prev->next->next;
        } else {
            prev = prev->next;
        }
    }
    return head;
    
}
````

***

**Java**

````java
 public ListNode removeElements(ListNode head, int val) {
    
         while (head != null && head.val == val) {
             head = head.next;
         }
         if (head == null ) {
             return head;
         }
         ListNode prev = head;
         while (prev.next != null) {
             if (prev.next.val == val) {
                 prev.next = prev.next.next;
             } else {
                 prev = prev.next;
             }
         }
         return head;
    }
````



***

### 设计链表

> 题目链接[设计链表](https://leetcode.cn/problems/design-linked-list/description/)

#### 题目描述

你可以选择使用单链表或者双链表，设计并实现自己的链表。

单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针/引用。

如果是双向链表，则还需要属性 prev 以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。

实现 MyLinkedList 类：

MyLinkedList() 初始化 MyLinkedList 对象。
int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
void addAtHead(int val) 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。

***

**C**

````c

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node *head;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
   MyLinkedList *obj = malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    Node* cur = obj->head;
    for(int i = 0; i < index; i++) {
        if(cur == NULL) return -1;
        cur = cur->next;
    }
    if(cur == NULL) return -1;
    return cur->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    myLinkedListAddAtIndex(obj,0,val);
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
      Node* newNode = malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    
    if(obj->head == NULL) {
        obj->head = newNode;
        return;
    }
    
    Node* cur = obj->head;
    while(cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = newNode;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
     if(index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    Node* cur = obj->head;
    for(int i = 0; i < index-1; i++) {
        if(cur == NULL) return;
        cur = cur->next;
    }
    if(cur == NULL) return;
    Node* newNode = malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = cur->next;
    cur->next = newNode;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
      if(index == 0) {
        Node* toDelete = obj->head;
        obj->head = obj->head->next;
        free(toDelete);
        return;
    }
    Node* cur = obj->head;
    for(int i = 0; i < index-1; i++) {
        if(cur == NULL) return;
        cur = cur->next;
    }
    if(cur == NULL || cur->next == NULL) return;
    Node* toDelete = cur->next;
    cur->next = cur->next->next;
    free(toDelete);
}

void myLinkedListFree(MyLinkedList* obj) {
      struct ListNode *cur = NULL, *tmp = NULL;
    for (cur = obj->head; cur;) {
        tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/
````

***

**Java**

````java
class MyLinkedList {
    int size;
    ListNode head;

    public MyLinkedList() {
        size = 0;
        head = new ListNode(0);
    }
    
    public int get(int index) {
        if ( index < 0 || index >= size) {
            return -1;
        }
        ListNode cur = head;
        for (int i = 0; i <= index ; i++) {
            cur = cur.next;
        }
        return cur.val;
    }
    
    public void addAtHead(int val) {
        addAtIndex(0,val);
    }
    
    public void addAtTail(int val) {
        addAtIndex(size,val);
    }
    
    public void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        }
        index = Math.max(0,index);
        size++;
        ListNode prev = head;
        for (int i = 0 ; i < index ; i++) {
            prev = prev.next;
        }
        ListNode add = new ListNode(val);
        add.next = prev.next;
        prev.next = add;

    }
    
    public void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        size--;
        ListNode prev = head;
        for (int i = 0 ; i < index; i++) {
            prev = prev.next;
        }
        prev.next = prev.next.next;
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
````

***

### 翻转链表

> 题目来源： [反转链表](https://leetcode.cn/problems/reverse-linked-list/)

#### 题目描述

给你单链表的头节点 head ，请你反转链表，并返回反转后的链表

#### 解题思路 

快慢指针 快指针进行逆向。慢指针保持链接

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
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    struct ListNode* temp = NULL;
    while (cur ) {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
}
````

***

**Java**

````java
 public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode cur = head;
        ListNode temp = null;
        while (cur != null) {
            temp = cur.next;// 保存下一个节点
            cur.next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }
````

