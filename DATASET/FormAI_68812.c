//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1000

void sanitizeInput(char input[]) {
    int i, j = 0;
    char sanitizedInput[MAX_INPUT_SIZE];
    for (i = 0; i < strlen(input); i++) {
        if (isalnum(input[i])) {
            sanitizedInput[j++] = input[i];
        }
    }
    sanitizedInput[j] = '\0';
    strcpy(input, sanitizedInput);
}

int main() {
    char input[MAX_INPUT_SIZE];
    printf("Please enter your name: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    sanitizeInput(input);
    printf("Hello %s!", input);
    return 0;
}