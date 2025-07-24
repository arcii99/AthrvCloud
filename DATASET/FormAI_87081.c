//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LENGTH 100

int main()
{
    char input[MAX_LENGTH];
    bool is_valid = true;

    printf("Enter some text:\n");
    fgets(input, MAX_LENGTH, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;

    // Iterate over input to sanitize it
    for(int i = 0; input[i] != '\0'; i++) {
        // Remove any non-alphanumeric characters
        if(!isalnum(input[i])) {
            is_valid = false;
            input[i] = ' ';
        } else {
            // Convert any uppercase letters to lowercase
            if(isupper(input[i])) {
                input[i] = tolower(input[i]);
            }
        }
    }

    if(is_valid) {
        printf("Your input is valid: %s\n", input);
        return 0;
    } else {
        printf("Your input contained invalid characters and has been sanitized: %s\n", input);
        return 1;
    }
}