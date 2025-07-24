//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 256

char* sanitize(char* string);

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string to sanitize:\n");
    fgets(input, MAX_LENGTH, stdin);
    printf("Sanitized string: %s", sanitize(input));
    return 0;
}

char* sanitize(char* string) {
    char* sanitized = calloc(MAX_LENGTH, sizeof(char));
    int j = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (isalnum(string[i])) {
            sanitized[j] = tolower(string[i]);
            j++;
        }
    }
    return sanitized;
}