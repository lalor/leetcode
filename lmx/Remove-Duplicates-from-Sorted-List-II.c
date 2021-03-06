#include <stdio.h>
#include <stdlib.h>

#define bool int
#define FALSE 0
#define TRUE 1


typedef struct ListNode {
    int val;
    struct ListNode *next;
}ListNode;


ListNode* initList(int a[], int size) {

    int i;
    if (size == 0 ){
        return NULL;
    }

    ListNode* head = (ListNode*)malloc(sizeof(*head));
    ListNode* previous = head;
    head->next = NULL;
    head->val = a[0];

    for (i = 1; i < size; i++) {
        ListNode* node = (ListNode*)malloc(sizeof(*node));
        previous->next = node;
        node->next = NULL;
        node->val = a[i];
        previous = node;
    }
    return head;
}

void printList(ListNode* head) {
    if (head == NULL) {
        printf("\n");
        return;
    } else {
        printf(" --> %d ", head->val);
        printList(head->next);
    }
}


int getListLength(struct ListNode* head) {
    int len = 0;
    while( head != NULL) {
    len++;
    head = head->next;
    }
    return len;

}

struct ListNode* moveOnList(struct ListNode* head, int distance) {
    while (distance--) {
    head = head->next;
    }
    return head;
}


struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL) return NULL;
    struct ListNode* p = head->next;
    head->next = NULL;

    struct ListNode* q;
    while ( p != NULL) {
        q = p->next;
        p->next = head;
        head = p;
        p=q;
    }
    return head;
}

struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    if ( m == n) {
        return head;
    }
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode *p = NULL;
    p = moveOnList(&dummy, n);
    struct ListNode *r = p->next;
    p->next = NULL;

    p = moveOnList(&dummy, m - 1);
    struct ListNode *q = p->next;
    p->next = NULL;

    p->next = reverseList(q);
    while (p->next != NULL) {
        p = p->next;
    }

    p->next = r;

    return dummy.next;
}

bool hasCycle(struct ListNode* head) {
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* fast = &dummy;
    struct ListNode* slow = &dummy;

    while( fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return TRUE;
        }
    }
    return FALSE;
}

struct ListNode *detectCycle(struct ListNode *head) {

    if (head == NULL) return NULL;

    struct ListNode* fast = head;
    struct ListNode* slow = head;


    do {
        if (fast->next == NULL || fast->next->next == NULL) { return NULL; }
        fast = fast->next->next;
        slow = slow->next;
    }while (slow != fast);

    slow = head;
    while(fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

struct ListNode* partition(struct ListNode* head, int x) {

    if (head == NULL || head->next == NULL) { return head;}

    struct ListNode a;
    struct ListNode* p = &a;

    struct ListNode b;
    struct ListNode* q = &b;

    struct ListNode* cur = head;

    while (cur != NULL) {
        if (cur->val < x) {
            p->next = cur;
            p = p->next;
        } else {
            q->next = cur;
            q = q->next;
        }
        cur = cur->next;
    }

    q->next = NULL;
    p->next = b.next;
    return a.next;

}


struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL) { return head; }
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* cur = &dummy;

    struct ListNode *rear = head;
    struct ListNode *front = head;

    while (front != NULL) {
        while( front->next != NULL && front->next->val == front->val) {
            front = front->next;
        }
        if (rear == front) {
            // 没有相等
            cur->next = rear; cur = rear;

            rear = rear->next; front = front->next;
        }
        else {
            //有相等的元素
            front = front->next; rear = front;
        }
    }

    cur ->next = NULL;
    return dummy.next;
    }

int main(int argc, char* argv[]) {
    int a[] = {1, 1, 2, 2, 5, 6};
    int i = 0;
    ListNode* head = initList(a, sizeof(a) / sizeof(int));
    printList(head);
    printList( deleteDuplicates(head));
}


