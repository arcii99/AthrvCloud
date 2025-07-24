//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_INPUT_SIZE 256

// Function to sanitize the user input
char* sanitizeInput(char* input) {
    // Removing leading and trailing whitespaces
    char* sanitizedInput = input;
    char* end;
    while(isspace((unsigned char)*sanitizedInput)) sanitizedInput++;
    if (*sanitizedInput == 0) return sanitizedInput;
    end = sanitizedInput + strlen(sanitizedInput) - 1;
    while(end > sanitizedInput && isspace((unsigned char)*end)) end--;
    *(end+1) = 0;
    
    // Removing unwanted characters
    char* sanitized = (char*)malloc(sizeof(char) * MAX_INPUT_SIZE);
    int j = 0;
    for(int i = 0; i < strlen(sanitizedInput); i++) {
        if(isalnum(sanitizedInput[i])) {
            sanitized[j++] = sanitizedInput[i];
        }
    }
    sanitized[j] = '\0';
    
    return sanitized;
}

int main() {
    char input[MAX_INPUT_SIZE];
    printf("Enter your input: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    char* sanitizedInput = sanitizeInput(input);
    printf("The sanitized input is: %s\n", sanitizedInput);
    free(sanitizedInput);
    return 0;
}