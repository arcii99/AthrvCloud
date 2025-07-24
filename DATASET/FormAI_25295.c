//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 1000

int main(void) {
    char input[MAX_INPUT_LENGTH] = {0};
    printf("Enter input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0; // remove newline character from fgets
    int len = strlen(input);

    // convert all characters to lowercase
    for (int i = 0; i < len; i++) {
        input[i] = tolower(input[i]);
    }

    // remove any character that isn't alphanumeric or whitespace
    char sanitized_input[MAX_INPUT_LENGTH] = {0};
    int sanitized_input_index = 0;
    for (int i = 0; i < len; i++) {
        if (isalnum(input[i]) || isspace(input[i])) {
            sanitized_input[sanitized_input_index++] = input[i];
        }
    }

    printf("Sanitized input: %s\n", sanitized_input);

    return 0;
}