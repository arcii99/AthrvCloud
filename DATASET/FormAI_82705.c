//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: calm
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to sanitize input
char* sanitizeInput(char* input) {

    // Remove leading and trailing white spaces
    char* sanitizedInput = strdup(input);
    char* end;

    // Remove leading white spaces
    while (isspace((unsigned char)*sanitizedInput)) {
        sanitizedInput++;
    }

    if (*sanitizedInput == 0) {
        return sanitizedInput;
    }

    // Remove trailing white spaces
    end = sanitizedInput + strlen(sanitizedInput) - 1;
    while (end > sanitizedInput && isspace((unsigned char)*end)) {
        end--;
    }

    // Add null character at the end of sanitized input
    *(end+1) = 0;

    return sanitizedInput;
}

int main() {

    char input[1000];

    // Get user input
    printf("Please enter a string: ");
    fgets(input, sizeof(input), stdin);

    printf("You entered: %s\n", input); // print user input before sanitization

    // Sanitize user input
    char* sanitizedInput = sanitizeInput(input);

    printf("Sanitized input: %s\n", sanitizedInput); // print sanitized user input

    return 0;
}