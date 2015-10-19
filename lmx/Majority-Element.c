#include <stdio.h>

int majorityElement(int* nums, int numsSize) {
    int element = nums[0];
    int count = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == element) {
            count++;
        } else {
            if (--count == 0) {
                element = nums[i];
                count = 1;
            }
        }
    }
    return element;
}
int main(int argc, char* argv[])
{
    int a[] = {1, 2, 1, 1, 1, 1, 1, 2, 1, 2, 4, 2, 1, 6, 2};
    int size = sizeof a / sizeof a[0];

    printf("%d\n", majorityElement(a, size));
    return 0;
}
