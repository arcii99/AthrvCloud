//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: creative
#include <stdio.h>
#include <string.h>

int main() {
    char str[100], revStr[100];
    int i, j, len;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    for (i = len - 1, j = 0; i >= 0; i--, j++) {
        revStr[j] = str[i];
    }

    revStr[j] = '\0';

    if (strcmp(str, revStr) == 0) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}