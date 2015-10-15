#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverseWord(char* p, char *q) {
    while ( p < q ) {
        char t = *p;
        *p = *q;
        *q = t;
        p++; q--;
    }
}

char* findSpace(char *p) {
    while (*p != '\0' && !isspace(*p)) {
        p++;
    }
    return p;
}

char* findChar(char *p) {
    while (*p != '\0' && isspace(*p)) {
        p++;
    }
    return p;
}


void reverse(char *str) {
    char *c = str; // char
    char *b = str; // blank
    while ( *c != '\0' && *b != '\0') {
        c = findChar(c);
        b = findSpace(c);
        if (c != b) {
        reverseWord(c, b - 1);
        }
        c = b;
    }
    reverseWord(str, c - 1);
}

int main(int argc, char* argv[])
{
    char str[] = "  the sky is blue   ";
    printf("%s\n", str);
    reverse(str);
    printf("%s\n", str);
    return 0;
}
