//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char input[100];
    printf("Enter your input: ");
    fgets(input, sizeof(input), stdin);

    printf("Your sanitized input: ");

    for (int i = 0; input[i]; i++) {
        if (isalpha(input[i])) {
            putchar(tolower(input[i]));
        } else if (isdigit(input[i])) {
            putchar(input[i]);
        } else if (isspace(input[i])) {
            putchar(' ');
        }
    }

    printf("\n");
    return 0;
}