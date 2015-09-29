#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
}ListNode;


struct ListNode* sumTwoNode(struct ListNode* node1, struct ListNode* node2, int carry) {

    if (node1 || node2 || carry > 0) {
        int a = node1 == NULL ? 0 : node1->val;
        int b = node2 == NULL ? 0 : node2->val;

        struct ListNode* ret = (struct ListNode*)malloc(sizeof(*ret));
        ret->val = (a + b + carry) % 10;
        ret->next = sumTwoNode(node1 == NULL ? NULL : node1->next,
                node2 == NULL ? NULL : node2->next,
                (a + b + carry) / 10);
        return ret;
    } else {
        return NULL;
    }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    return sumTwoNode(l1, l2, 0);
}


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



int main(int argc, char* argv[]) {
    int a[] = {4, 9};
    int b[] = {5, 6, 9};
    ListNode* alist = initList(a, sizeof(a) / sizeof(int));
    ListNode* blist = initList(b, sizeof(b) / sizeof(int));
    ListNode* result = NULL;
    result = addTwoNumbers(alist, blist);

    printList(alist);
    printList(blist);
    printList(result);

    printf("----------------------------------------\n");
    return 0;
}
