#include <stdio.h>

int findKthLargest(int* nums, int numsSize, int k) {

}


int main(int argc, char* argv[])
{
    int a[] = {1, 3, 2, 5, 4, 6, 7};
    int size = sizeof a / sizeof a[0];
    printf("%d\n", findKthLargest(a, size, 2));
    return 0;
}
#include <stdio.h>

/**
 *快速排序的经典实现，参考《编程珠玑》11章
 */
int partation(int x[], int l, int u)
{
    if ( l >=u ) return u;
    int t = x[l], i = l , j = u + 1;
    while ( 1 )
    {
        do i++; while( i <= u && x[i] < t);
        do j--; while( x[j] > t);
        if ( i > j) break;
        //swap i, j
        int temp = x[i]; x[i] = x[j]; x[j] = temp;
    }
    //swap j, l
    int temp = x[l]; x[l] = x[j]; x[j] = temp;
    return j;
}

void qsort(int x[], int l, int u)
{
    if( l >= u) return;
    int m = partation(x, l, u);
    qsort(x, l, m-1);
    qsort(x, m+1, u);
}

int select(int x[], int len, int key)
{
    int l = 0, u = len - 1;
    while ( l <= u)
    {
        int k = partation(x, l, u);
        if ( x[k] == key) return k;
        else if ( x[k] < key) l = k + 1;
        else u = k - 1;
    }
    return -1;
}

int findKthLargest(int* nums, int numsSize, int k) {
    int l = 0, u = numsSize - 1;
    int m = -1;

    k = numsSize - k;
    while ( 1 ) {
        m = partation(nums, l, u);
        if (m == k) {
            return nums[m];
        } else if ( m < k ) {
            l = m + 1;
        } else {
            u = m -1;
        }
    }
}

int main(int argc, char* argv[])
{
    int data[] = {2, 4, 5, 6, 7, 8, 9, 1, 12, 34, 8};
    int size = sizeof data / sizeof data[0];

    printf("-------> %d\n", findKthLargest(data, size, 3));
    qsort(data, 0, size - 1);
    for (int i = 0; i < size; i++) {
        printf("%d\t", data[i]);
    }
    printf("\n");

    return 0;
}
