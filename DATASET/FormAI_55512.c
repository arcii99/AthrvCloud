//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: single-threaded
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 50

char* sanitize_input(char* input) {
    char temp[MAX_INPUT_LENGTH];
    int i, j = 0;

    for (i = 0; input[i] != '\0'; i++) {
        if (isalnum(input[i])) {
            temp[j++] = input[i];
        }
    }
    temp[j] = '\0';

    strcpy(input, temp);
    return input;
}

int main() {
    char input[MAX_INPUT_LENGTH];

    printf("Enter a string: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    printf("Original input: %s\n", input);

    sanitize_input(input);
    
    printf("Sanitized input: %s\n", input);

    return 0;
}