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


struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* p = moveOnList(&dummy, getListLength(&dummy) - n - 1);
    p->next = p->next->next;;
    return dummy.next;

}


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL) {
        return l2;
    } else if (l2 == NULL) {
        return l1;
    }

    if ( l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

struct ListNode* merge( struct ListNode* a, struct ListNode* b)
{
     struct ListNode result;
     struct ListNode* cur = &result;
     while ( a != NULL && b != NULL )
     {
         if ( a->val < b->val ) { cur->next = a; a = a->next; }
         else { cur->next = b; b = b->next; }
         cur = cur->next;
     }

    cur->next = ( a == NULL ? b : a );
    return result.next;
}

struct ListNode* sortList(struct ListNode* head) {
    struct ListNode* slow;
    struct ListNode* fast;
    if ( head == NULL || head->next == NULL) return head;
    slow = head; fast = head->next;
    while ( fast != NULL && fast->next != NULL )
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    slow->next = NULL;
    slow = head;
    return merge(sortList(slow), sortList(fast));
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize > 1) {
        int half = listsSize / 2;
        return merge(mergeKLists(lists, half), mergeKLists(lists + half, listsSize - half));
    } else {
        return sortList(lists[0]);
    }
}


int main(int argc, char* argv[]) {
    int a[] = {1,  3,  5};
    int b[] = {2,  4,  6};
    int c[] = {-5,  9,  7};
    int d[] = {-2,  0,  8};


    ListNode* ahead = initList(a, sizeof(a) / sizeof(int));
    ListNode* bhead = initList(b, sizeof(b) / sizeof(int));
    ListNode* chead = initList(c, sizeof(c) / sizeof(int));
    ListNode* dhead = initList(d, sizeof(d) / sizeof(int));

    struct ListNode* lists[] = {ahead, bhead, chead, dhead};

    printList( mergeKLists(lists, 4));
}


