#include <stdio.h>

void swap(int *front, int *rear) {
    int temp = *front;
    *front = *rear;
    *rear = temp;
}

int removeElement(int* nums, int numsSize, int val) {
    int *front = nums;
    int *rear = nums + numsSize - 1;
    while ( front <= rear) {

        while ( front <= rear && *rear == val) {
            rear--;
        }
        while ( front <= rear && *front != val ) {
            front++;
        }
        if ( front < rear ) {
            swap(front, rear);
        } else {
            break;
        }

        front++;
        rear--;
    }
    return rear - nums + 1;
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
    int a[] = { 1, 1, 1};
    int len = 0;
    printArr(a, sizeof(a) / sizeof(int));

    len = removeElement(a, sizeof(a) / sizeof(int), 1);
    printf("%d\n", len);
    printArr(a, len);

    return 0;
}
