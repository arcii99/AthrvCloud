//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char input[100];
    printf("Enter some text: ");
    fgets(input, 100, stdin);

    // Remove newline character at the end
    int i = 0;
    while (input[i] != '\n') {
        i++;
    }
    input[i] = '\0';

    // Convert all characters to uppercase
    i = 0;
    while (input[i]) {
        input[i] = toupper(input[i]);
        i++;
    }

    // Remove all non-alphanumeric characters
    char sanitized[100];
    int j = 0;
    i = 0;
    while (input[i]) {
        if (isalnum(input[i])) {
            sanitized[j] = input[i];
            j++;
        }
        i++;
    }
    sanitized[j] = '\0';

    printf("Sanitized input: %s\n", sanitized);

    return 0;
}