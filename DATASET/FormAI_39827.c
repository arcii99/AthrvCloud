//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: future-proof
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LEN 1000

int main(void) {
    char input[MAX_INPUT_LEN];

    printf("Enter input: ");
    fgets(input, MAX_INPUT_LEN, stdin);

    // Remove newline character from input
    if (strlen(input) > 0 && input[strlen(input)-1] == '\n')
        input[strlen(input)-1] = '\0';

    // Convert all characters to lowercase
    for (int i = 0; i < strlen(input); i++) {
        input[i] = tolower(input[i]);
    }

    char sanitized_input[MAX_INPUT_LEN];
    int j = 0;
    // Remove any characters that are not alphanumeric
    for (int i = 0; i < strlen(input); i++) {
        if (isalnum(input[i])) {
            sanitized_input[j] = input[i];
            j++;
        }
    }
    sanitized_input[j] = '\0';

    printf("Sanitized input: %s\n", sanitized_input);

    return 0;
}