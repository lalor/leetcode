#include <stdio.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

void deleteNode(struct ListNode* node) {
    struct ListNode* front = node->next;
    node->val = front->val;
    node->next = front->next;
    free(front);
}

int main(int argc, char* argv[])
{
    return 0;
}
