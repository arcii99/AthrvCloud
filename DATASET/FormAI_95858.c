//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Function signature */
void sanitizeInput(char* userInput);

/* Main function */
int main() {
    char userInput[100];
    printf("Enter your message:\n");
    fgets(userInput, 100, stdin); // Get user input
    sanitizeInput(userInput); // Sanitize user input
    printf("Your sanitized message is: %s\n", userInput); // Print sanitized input
    return 0;
}

/* Function definition */
void sanitizeInput(char* userInput) {
    int i, j;
    char sanitizedInput[100];
    for(i = 0, j = 0; i<strlen(userInput); i++) {
        if(isalpha(userInput[i]) || isspace(userInput[i])) {
            sanitizedInput[j++] = userInput[i];
        }
    }
    sanitizedInput[j] = '\0'; // Append null character at the end
    strcpy(userInput, sanitizedInput); // Replace user input with sanitized input
}