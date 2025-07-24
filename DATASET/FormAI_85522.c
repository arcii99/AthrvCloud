//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];
    char reversed[100];
    int i, j, len;

    printf("Enter a string: ");
    scanf("%s", str);
    len = strlen(str);

    for (i = 0, j = len - 1; i < len; i++, j--) {
        reversed[j] = str[i];
    }

    reversed[len] = '\0';

    if (strcmp(str, reversed) == 0) {
        printf("\n%s is a palindrome!\n", str);
    } else {
        printf("\n%s is not a palindrome!\n", str);
    }

    return 0;
}