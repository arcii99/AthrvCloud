//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: genious
#include <stdio.h>
#include <string.h>

// Function to sanitize user input
void sanitizeInput(char* input) {
    int i, j;
    char temp;

    // Loop over each character in the input
    for(i = 0, j = strlen(input) - 1; i < j; i++, j--) {
        // Swap each character from start and end
        temp = input[i];
        input[i] = input[j];
        input[j] = temp;
    }

    // Replace any instances of '!' with '?'
    for(i = 0; i < strlen(input); i++) {
        if(input[i] == '!') {
            input[i] = '?';
        }
    }
}

// Main function
int main() {
    char input[50];

    printf("Enter your input: ");
    scanf("%s", input);

    // Sanitize the user input
    sanitizeInput(input);

    printf("Sanitized input: %s\n", input);

    return 0;
}