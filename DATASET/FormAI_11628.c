//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void sanitizeInput(char *input, int size);

int main() {
    char input[50];
    printf("Please enter your input: ");
    fgets(input, 50, stdin);
    sanitizeInput(input, sizeof(input));
    printf("Sanitized input: %s", input);
    return 0;
}

void sanitizeInput(char *input, int size) {
    // Convert all uppercase letters to lowercase
    for(int i=0; i<size; i++) {
        if(input[i] >= 'A' && input[i] <= 'Z') {
            input[i] = tolower(input[i]);
        }
    }

    // Remove all non-alphanumeric characters
    char *sanitized = malloc(size * sizeof(char));
    int j = 0;
    for(int i=0; i<size; i++) {
        if(isalnum(input[i])) {
            sanitized[j] = input[i];
            j++;
        }
    }
    sanitized[j] = '\0';

    // Copy sanitized string back into input array
    strncpy(input, sanitized, size);

    // Free dynamic memory
    free(sanitized);
}