//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

void sanitizeInput(char *input) {
    // loop through each character in input string
    for (int i = 0; i < strlen(input); i++) {
        // check if character is alphanumeric
        if (!isalnum(input[i])) {
            // replace non-alphanumeric character with space
            input[i] = ' ';
        }
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter your input:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin); // get input from user
    
    // sanitize input
    sanitizeInput(input);
    
    // display sanitized input
    printf("Sanitized input: %s\n", input);
    
    return 0;
}