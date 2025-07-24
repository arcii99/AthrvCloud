//FormAI DATASET v1.0 Category: Word Count Tool ; Style: standalone
#include <stdio.h>
#include <string.h>

// Declare function to count number of words
int countWords(char string[]);

// Start main function
int main() {
    // Declare variables
    char input[1000];

    // Get input from user
    printf("Enter a sentence to count words: ");
    fgets(input, 1000, stdin);

    // Remove newline character at end of input
    input[strlen(input) - 1] = '\0';

    // Call countWords function and print result
    printf("Number of words: %d", countWords(input));

    return 0;
}

// Start countWords function
int countWords(char string[]) {
    // Declare variables
    int count = 0, i;

    // Check each character in string
    for (i = 0; string[i] != '\0'; i++) {
        // If character is a space or a tab or a newline or a hyphen
        if (string[i] == ' ' || string[i] == '\t' || string[i] == '\n' || string[i] == '-') {
            // Increment word count
            count++;
        }
    }

    // Add one to word count for last word in string
    count++;

    // Return the total word count
    return count;
}