//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define BUFFER_SIZE 1024

char* sanitize_input(char* input);

int main() {
    char buffer[BUFFER_SIZE];
    printf("Please enter a string: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    char* sanitized = sanitize_input(buffer);
    printf("Sanitized input: %s\n", sanitized);
    free(sanitized);
    return 0;
}

char* sanitize_input(char* input) {
    char* sanitized = (char*)malloc(sizeof(char) * BUFFER_SIZE);
    int i = 0, j = 0;
    while (input[i] != '\0') {
        if (isalpha(input[i])) {
            sanitized[j] = tolower(input[i]);
            j++;
        }
        else if (isdigit(input[i])) {
            sanitized[j] = input[i];
            j++;
        }
        i++;
    }
    sanitized[j] = '\0';
    return sanitized;
}