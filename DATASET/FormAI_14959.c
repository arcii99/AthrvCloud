//FormAI DATASET v1.0 Category: Data validation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

bool isNumeric(char* s);

int main() {
    char input[100];

    printf("Enter a number: ");
    fgets(input, sizeof(input), stdin);

    if (isNumeric(input)) {
        printf("The input is a valid number.\n");
    } else {
        printf("The input is not a valid number.\n");
    }

    return 0;
}

/* Returns true if s is a valid number */
bool isNumeric(char* s) {
    int i = 0;

    /* check for negative sign */
    if (s[0] == '-') {
        i++;
    }

    /* check for digits */
    for (; s[i] != '\0'; i++) {
        /* if not a digit return false */
        if (!isdigit(s[i])) {
            return false;
        }
    }

    /* if all characters are digits return true */
    return true;
}