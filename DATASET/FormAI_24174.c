//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: genious
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

// Function to sanitize the user input
void sanitize_input(char *input) {
    int index1 = 0, index2 = 0;
  
    // Traverse through each char of input string
    while (input[index1] != '\0') {
        // Check if the current char is a letter
        if (isalpha(input[index1])) {
            // Convert the letter to lowercase
            input[index2] = tolower(input[index1]);
            index2++;
        }
        index1++;
    }

    // Add null character to the end of sanitized string
    input[index2] = '\0';
}

int main() {
    char input[MAX_INPUT_LENGTH];

    // Get user input
    printf("Enter your input:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Sanitize the input
    sanitize_input(input);

    // Print sanitized input
    printf("Sanitized input: %s", input);

    return 0;
}