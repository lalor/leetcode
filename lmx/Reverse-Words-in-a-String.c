#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverseWord(char* str, int i, int j) {
    while (i < j) {
        int t = str[i];
        str[i] = str[j];
        str[j] = t;
        i++;
        j--;
    }
}

void reverse(char *str, int size) {
    int i = 0, j = 0;

    // skip space in front
    int k = -1;
    while(isspace(str[++k]))
    {
    }

    for (k; k < size; k++) {
    }
}

int main(int argc, char* argv[])
{
    char str[] = "the sky is blue";
    reverse(str, sizeof(str));
    printf("%s\n", str);
    return 0;
}
