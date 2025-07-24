//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to sanitize user input
void sanitize_input(char *input_string) {
    char sanitized_string[100]; // buffer to hold sanitized string
    int i = 0, j = 0;
    int length = strlen(input_string);

    // Loop through the input string, removing any non-alphanumeric characters
    for (i = 0; i < length; i++) {
        if (isalnum(input_string[i])) {
            // If the current character is alphanumeric, add it to the sanitized string
            sanitized_string[j] = input_string[i];
            j++; // Update the index in the sanitized string
        }
    }

    // Copy the sanitized string back to the input string
    strcpy(input_string, sanitized_string);
}

int main() {
    char input_string[100];
    printf("Please enter a string:\n");
    fgets(input_string, 100, stdin);

    printf("You entered: %s\n", input_string);

    sanitize_input(input_string);
    
    printf("Sanitized input: %s\n", input_string);

    return 0;
}