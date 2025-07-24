//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

char* sanitizeInput(char* input) {
    char* sanitized = malloc(MAX_INPUT_SIZE * sizeof(char));
    int i = 0, j = 0;

    while(input[i] != '\0') {
        if(isalnum(input[i])) {
            sanitized[j] = tolower(input[i]);
            j++;
        }
        i++;
    }

    sanitized[j] = '\0';
    return sanitized;
}

int main() {
    char input[MAX_INPUT_SIZE];

    printf("Enter some text: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    char* sanitizedInput = sanitizeInput(input);

    printf("Sanitized input: %s\n", sanitizedInput);

    free(sanitizedInput);

    return 0;
}