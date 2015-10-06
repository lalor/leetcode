#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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

struct ListNode* moveOnList(struct ListNode* head, int distance) {
    while (distance--) {
    head = head->next;
    }
    return head;
}



bool isPalindrome(struct ListNode* head) {
    int len = getListLength(head);
    int half = len / 2;

    if (head==NULL) {
    return TRUE;
    }
    struct ListNode* midpoint = moveOnList(head, (len - 1)/2);
    midpoint->next  = reverseList(midpoint->next);
    struct ListNode* p = midpoint->next;

    while (half--) {
        if (head->val != p->val)
        {
            return FALSE;
        } else {
        head = head->next;
        p = p->next;
        }
    }
    return TRUE;
}

int main(int argc, char* argv[]) {
    int a[] = {};
    int i = 0;
    ListNode* head = initList(a, sizeof(a) / sizeof(int));
    printList(head);
    assert(isPalindrome(head) == TRUE);
    printList(head);
}
