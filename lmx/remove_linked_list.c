#include <stdio.h>
#include <stdlib.h>

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

ListNode* removeElements(ListNode *head, int val) {
    if (head == NULL) {
    return NULL;
    } else if (head->val == val) {
        ListNode* next = head->next;
        return removeElements(next, val);
    } else {
    head->next = removeElements(head->next, val);
    }
}

int main(int argc, char* argv[]) {
    int a[] = {6, 6, 1};
    int i = 0;
    ListNode* head = initList(a, sizeof(a) / sizeof(int));
    printList(head);

    printf("----------------------------------------\n");
    printList(removeElements(head, 6));
    return 0;
}
