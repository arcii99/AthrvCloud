//FormAI DATASET v1.0 Category: Word Count Tool ; Style: all-encompassing
#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main() {
    char inputString[MAX_LENGTH];
    int characterCount = 0, wordCount = 0, lineCount = 0;

    printf("Enter your text:\n");

    // Input loop
    while (fgets(inputString, MAX_LENGTH, stdin) != NULL) {
        // Iterating through each character in the input string
        for (int i = 0; inputString[i] != '\0'; i++) {
            characterCount++;

            // Checking for end of line
            if (inputString[i] == '\n') {
                lineCount++;
            }

            // Checking for word count
            if (isspace(inputString[i]) || inputString[i] == '\n') {
                wordCount++;
            }
        }
    }
    // Printing the results
    printf("Number of characters in the input: %d\n", characterCount);
    printf("Number of words in the input: %d\n", wordCount);
    printf("Number of lines in the input: %d\n", lineCount);

    return 0;
}