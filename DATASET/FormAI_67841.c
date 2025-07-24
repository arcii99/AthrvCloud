//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: invasive
#include <stdio.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100 // Maximum size of user input

int main() {
    char input[MAX_INPUT_SIZE]; // User input buffer
    int i = 0; // Iterator for processing input

    printf("Enter a string to sanitize: \n");
    fgets(input, sizeof(input), stdin); // Read user input

    // Loop through each character of the input
    while (input[i] != '\0') {
        if (isalnum(input[i])) { // Check if character is alphanumeric
            putchar(input[i]); // Print the character as is
        } else if (isspace(input[i])) { // Check if character is whitespace
            putchar(' '); // Replace whitespace with a single space
            while (isspace(input[i+1])) { // Ignore consecutive whitespace
                i++; 
            }
        } else { // Character is not alphanumeric or whitespace
            putchar('_'); // Replace non-alphanumeric characters with an underscore
        }
        i++;
    }
    return 0;
}