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


struct ListNode* rotateRight(struct ListNode* head, int k) {

    int len = getListLength(head);

    if ( len <= 1) {
        return head;
    }

    k = k % len;
    if ( k == 0 ) {
        return head;
    }

    struct ListNode *p = moveOnList(head, len - k - 1);
    struct ListNode *q = p->next;
    p->next = NULL;

    p = q;
    while (q->next != NULL) {
        q = q->next;
    }
    q->next = head;
    return p;
}


int main(int argc, char* argv[]) {
    int a[] = {1, 2, 3, 4, 5};
    ListNode* head = initList(a, sizeof(a) / sizeof(int));
    printList(head);
    printList( rotateRight(NULL, 1) );
}
