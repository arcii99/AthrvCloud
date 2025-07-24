//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sanitizeInput(char* input) {
    int length = strlen(input);
    char sanitizedInput[length+1];
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (isalnum(input[i])) {
            sanitizedInput[j] = tolower(input[i]);
            j++;
        }
    }
    sanitizedInput[j] = '\0';
    strcpy(input, sanitizedInput);
}

int main() {
    char name[50];
    printf("Enter your name: ");
    fgets(name, 50, stdin);
    sanitizeInput(name);
    printf("Hello, %s!\n", name);
    return 0;
}