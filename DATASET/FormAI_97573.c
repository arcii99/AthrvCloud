//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: surprised
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter some input: ");
    fgets(input, sizeof(input), stdin);

    printf("Your sanitized input is: ");

    // Remove any non-alphanumeric characters
    for (int i = 0; i < strlen(input); i++) {
        if (isalnum(input[i])) {
            putchar(input[i]);
        }
    }

    printf("\n");

    return 0;
}
