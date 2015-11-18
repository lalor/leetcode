#include <stdio.h>
#include<assert.h>

int howMuchFive(int n) {
    int i = 0;
    while ( n != 0) {
        if ( n % 5 == 0 ) { i++; }
        n /= 5;
    }
    return i;
}


int trailingZeroes(int n) {
    int sum = 0;

    int i = 0;
    for ( ; i <= n; i++) {
        sum += howMuchFive(i);
    }

    return sum;
}

int main(int argc, char* argv[])
{

    assert(trailingZeroes(3) == 0);
    assert(trailingZeroes(5) == 1);
    assert(trailingZeroes(6) == 1);

    assert(trailingZeroes(9) == 1);
    assert(trailingZeroes(10) == 2);
    assert(trailingZeroes(11) == 2);
    return 0;
}
