//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sanitizeInput(char *input) {
    int i, j;
    char temp[50];
    
    for (i = 0, j = 0; input[i] != '\0'; i++) {
        if (isalnum(input[i]) || isspace(input[i])) {
            temp[j++] = input[i];
        }
    }
    
    temp[j] = '\0';
    strcpy(input, temp);
}

int main() {
    char userInput[50];
    
    printf("Please enter your input: ");
    fgets(userInput, 50, stdin);
    
    sanitizeInput(userInput);
    
    printf("Sanitized input: %s", userInput);
    
    return 0;
}