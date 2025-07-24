//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: random
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a character is an alpha-numeric character
bool isAlphaNumeric(char c) {
    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return true;
    return false;
}

// Function to sanitize user input
char* sanitizeInput(char* input) {
    int len = strlen(input);
    char* sanitizedInput = (char*)malloc(sizeof(char) * (len+1));
    int j = 0;
    for (int i=0; i<len; i++) {
        if (isAlphaNumeric(input[i])) {
            sanitizedInput[j++] = input[i];
        } else {
            sanitizedInput[j++] = '_';
        }
    }
    sanitizedInput[j] = '\0';
    return sanitizedInput;
}

int main() {
    char input[100];
    printf("Enter your input:");
    scanf("%[^\n]%*c", input);
    char* sanitizedInput = sanitizeInput(input);
    printf("Your sanitized input is: %s\n", sanitizedInput);
    free(sanitizedInput);
    return 0;
}