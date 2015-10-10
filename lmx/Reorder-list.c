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

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
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

struct ListNode* crossMergeList( struct ListNode* a, struct ListNode* b) {
    struct ListNode dummy;
    struct ListNode* cur = &dummy;
    while (a != NULL && b != NULL) {
        cur->next = a; cur = cur->next; a = a->next;
        cur->next = b; cur = cur->next; b = b->next;
    }
    cur->next = (a != NULL ? a : b);
    return dummy.next;
}


void reorderList(struct ListNode* head) {

    if (head == NULL || head->next == NULL || head->next->next == NULL) return;

    struct ListNode* slow = head;
    struct ListNode* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    fast = slow->next;
    slow->next = NULL;
    slow = head;


    fast = reverseList(fast);
    *(&head) = crossMergeList(slow, fast);
}

int main(int argc, char* argv[]) {
    int a[] = {1, 2, 3};
    ListNode* head = initList(a, sizeof(a) / sizeof(int));
    printList(head);
    reorderList(head);
    printList(head);
}
