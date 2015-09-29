#include <stdio.h>

void swap(int *front, int *rear) {
    int temp = *front;
    *front = *rear;
    *rear = temp;
}

int moveZeroes(int* nums, int numsSize) {
    // [0, 1, 0, 3, 12]
    int numOfZero = 0;
    int i = 0;
    for(i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            numOfZero++;
        } else if (numOfZero != 0) {
            swap(nums + i, nums + i - numOfZero);
        }
    }
    return numsSize - numOfZero;
}


void printArr(int *nums, int numsSize) {
    int i;
    for( i=0; i < numsSize; i++) {
        printf("%d  ", nums[i]);
    }
    printf("\n");
}

int main(int argc, char* argv[])
{
    int a[] = { 1, 0, 0, 0, 0};
    int len = 0;
    printArr(a, sizeof(a) / sizeof(int));
    len = moveZeroes(a, sizeof(a) / sizeof(int));
    printf("%d\n", len);
    printArr(a, len);

    return 0;
}
