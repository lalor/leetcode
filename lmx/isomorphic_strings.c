#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAX_SIZE 256
#define TRUE 1
#define FALSE 0
#define bool int


bool isIsomorphic(char* s, char* t) {
    int a[255] = {0};
    int b[255] = {0};

    while (*s != '\0' && *t != '\0') {
        if (a[*s] == 0 && b[*t] == 0 )
        {
            a[*s] = *t;
            b[*t] = *s;
            continue;
        }

        if (a[*s] != *t || b[*t] != *s ) {
        return FALSE;
        }

        s++; t++;
    }

    if (*s != '\0' || *t != '\0') {
    return FALSE;
    } else {
    return TRUE;
    }
}

int main(int argc, char* argv[])
{
    assert(isIsomorphic("a", "a") == TRUE);
    assert(isIsomorphic("b", "a") == TRUE);
    assert(isIsomorphic("", "") == TRUE);
    assert(isIsomorphic("egg", "add") == TRUE);
    assert(isIsomorphic("foo", "bar") == FALSE);
    assert(isIsomorphic("paper", "title") == TRUE);
    assert(isIsomorphic("ab", "aa") == FALSE);
    return 0;
}

