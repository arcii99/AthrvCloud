//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

int main() {
    char input[MAX_LEN];
    int i, j, len;

    printf("Enter a string: ");
    fgets(input, MAX_LEN, stdin);

    len = strlen(input);

    for (i = 0; i < len; i++) {
        if (!isalnum(input[i])) {
            input[i] = ' ';
        } else if (isupper(input[i])) {
            input[i] = tolower(input[i]);
        }
    }

    for (i = 0; i < len; i++) {
        if (input[i] != ' ') {
            break;
        }
    }

    for (j = len - 1; j >= 0; j--) {
        if (input[j] != ' ') {
            break;
        }
    }

    printf("Sanitized Input: ");
    for (; i <= j; i++) {
        putchar(input[i]);
    }
    putchar('\n');

    return 0;
}