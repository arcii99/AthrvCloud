//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to sanitize user input
void sanitizeInput(char *input) {
    int i, j = 0;
    char temp[strlen(input)]; // Temporary array to store sanitized input
    
    // Convert input to lowercase
    for (i = 0; input[i]; i++) {
        temp[i] = tolower(input[i]);
    }
    temp[i] = '\0';
    
    // Remove leading and trailing whitespaces
    for (i = 0; temp[i] == ' '; i++);  // Skip over leading whitespaces
    for (j = strlen(temp) - 1; j > 0 && temp[j] == ' '; j--);  // Skip over trailing whitespaces
    temp[j + 1] = '\0';
    
    // Remove all non-alphanumeric characters except whitespaces
    for (i = 0; temp[i]; i++) {
        if (isalnum(temp[i]) || temp[i] == ' ') {
            input[i] = temp[i];
        }
    }
    input[i] = '\0';
}

// Driver function
int main() {
    char input[100];
    
    printf("Enter some text: ");
    fgets(input, sizeof(input), stdin);
    
    // Remove newline character from input
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }
    
    sanitizeInput(input);
    printf("Sanitized input: %s\n", input);
    
    return 0;
}