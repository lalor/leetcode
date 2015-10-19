#include <stdio.h>

void reverse(int *nums, int i, int j) {

    while ( i < j) {
        int t = nums[i]; nums[i] = nums[j]; nums[j] = t;
        i++; j--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    reverse(nums, 0, numsSize - k - 1);
    reverse(nums, numsSize - k, numsSize - 1);
    reverse(nums, 0, numsSize - 1);
}

int main(int argc, char* argv[])
{
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof a / sizeof a[0];
    rotate(a, size, 3);

    for (int i = 0; i < size; i++)
    {
        printf("%d", a[i]);
        printf("\n");
    }
    return 0;
}
