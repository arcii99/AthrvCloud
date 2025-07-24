//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    int i, j;

    printf("Enter your input: ");
    fgets(input, sizeof(input), stdin);

    // removing trailing newline character
    input[strcspn(input, "\n")] = 0;

    // removing leading and trailing whitespaces
    while (input[0] == ' ') {
        memmove(input, input+1, strlen(input));
    }

    for (i = strlen(input) - 1; i >= 0 && input[i] == ' '; i--) {
        input[i] = '\0';
    }

    // replacing consecutive whitespaces with a single space
    for (i = 0, j = 0; i < strlen(input); i++) {
        if (input[i] != ' ') {
            input[j++] = input[i];
        } else if (j > 0 && input[j-1] != ' ') {
            input[j++] = input[i];
        }
    }
    input[j] = '\0';

    // Check if sanitized input contains only digits
    int only_digits = 1;
    for (i = 0; i < strlen(input); i++) {
        if (input[i] < '0' || input[i] > '9') {
            only_digits = 0;
            break;
        }
    }

    if (only_digits) {
        printf("\nGreat! Your input contains only digits.\n");
    } else {
        printf("\nOops! Your input contains non-digit characters, they have been removed.\n");
    }

    printf("\nSanitized input: %s\n", input);

    return 0;
}