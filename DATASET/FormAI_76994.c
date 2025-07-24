//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: sophisticated
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

void sanitizeInput(char inputString[], int inputLength);

int main() {
    char userInput[MAX_INPUT_LENGTH];
    printf("Enter input to sanitize: ");
    fgets(userInput, MAX_INPUT_LENGTH, stdin);
    int inputLength = strlen(userInput);
    sanitizeInput(userInput, inputLength);
    printf("The sanitized input is: %s", userInput);
    return 0;
}

void sanitizeInput(char inputString[], int inputLength) {
    char sanitizedInput[MAX_INPUT_LENGTH];
    int sanitizedLength = 0;
    for(int i=0; i < inputLength; i++) {
        char currentChar = inputString[i];
        if(isalnum(currentChar) || currentChar == ' ') { 
            sanitizedInput[sanitizedLength++] = currentChar;
        }
    }
    sanitizedInput[sanitizedLength] = '\0'; 
    strcpy(inputString, sanitizedInput);
}