#include <stdio.h>
#include <stdlib.h>

#define bool int
#define FALSE 0
#define TRUE 1


typedef struct ListNode {
    int val;
    struct ListNode *next;
}ListNode;

typedef struct ListNode* link;

void sortInsert(struct ListNode** pHead, link newNode)
{
    link head = *pHead;
    if(head == NULL || newNode == NULL)return;

    if (newNode->val <= head->val )
    { newNode->next = head; *pHead = newNode;return; }

    while ( head->next != NULL && head->next->val < newNode->val)
    {
        head = head->next;
    }
    newNode->next = head->next;
    head->next = newNode;
}


//insert sort
struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode** phead = &head;
    link cur = NULL;
    link next = NULL;

    if (head == NULL) return NULL;

    cur = head->next;
    head->next = NULL;
    while ( cur != NULL )
    {
        next = cur->next;
        cur->next = NULL;
        sortInsert(phead, cur);
        cur = next;
    }
    return *phead;
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
link merge( link a, link b)
{
    struct ListNode result;
    link cur = &result;
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
    link slow, fast;
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

int main(int argc, char* argv[]) {
    int a[] = {1, 3, 5, 0, 5};
    int i = 0;
    ListNode* head = initList(a, sizeof(a) / sizeof(int));
    printList(head);
    printList(insertionSortList(head));
}
