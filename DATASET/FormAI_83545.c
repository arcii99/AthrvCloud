//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Alan Touring
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100

char sanitizeCharacter(char c) {
    if (isalpha(c)) {
        return tolower(c);
    } else if (isdigit(c)) {
        return c;
    } else {
        return '\0';
    }
}

void sanitizeInput(char *input) {
    int i;
    char sanitized[MAX_INPUT_SIZE];
    for (i = 0; i < strlen(input); i++) {
        char c = sanitizeCharacter(input[i]);
        if (c != '\0') {
            sanitized[strlen(sanitized)] = c;
        }
    }
    strcpy(input, sanitized);
}

int main(void) {
    char input[MAX_INPUT_SIZE];
    printf("Enter some input: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    sanitizeInput(input);
    printf("Sanitized input: %s\n", input);
    return 0;
}