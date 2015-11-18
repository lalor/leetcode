#include <stdio.h>
#include <stdlib.h>


void voteElement(int* elements, int* tickets, int size, int elem) {
    for (int i = 0; i < size; i++) {
        if (elements[i] == elem) {
            tickets[i] += size;
            return;
        } else {
            tickets[i] -= 1;
        }
    }

    for ( int i = 0; i < size; i++) {
        if (tickets[i] <= 0) {

            elements[i] = elem;
            tickets[i] = size;
        }
    }

}

int* majorityElement(int* nums, int numsSize, int* returnSize) {
    int a[] = {nums[0], nums[1], nums[2]};
    int aTickets[] = {3, 3, 3};

    for (int i = 3; i < numsSize; i++) {
        voteElement(a, aTickets, 3, nums[i]);
    }

    int *r = (int*)malloc(sizeof(int) * 3);
    int count = 0;
    for ( int i=0; i < 3; i++) {
        if (aTickets[i] > 0) {
            r[count++] = a[i];
        }
    }
    *returnSize = count;
    return r;
}

int main(int argc, char* argv[])
{
    int a[] = {1, 2, 1, 1, 1, 1, 1, 2, 1, 2, 4, 2, 1, 6, 2};
    int size = sizeof a / sizeof a[0];
    int returnSize = 0;

    int *r = majorityElement(a, size, &returnSize);
    for ( int i=0; i < returnSize; i++) {
        printf("%d\n", r[i]);
    }

    return 0;
}
