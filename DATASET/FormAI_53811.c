//FormAI DATASET v1.0 Category: Word Count Tool ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_SIZE 10000

int main() {

    char inputString[MAX_STRING_SIZE];  // Initialize array to store user input
    int wordCount = 0;  // Initialize word count to zero

    // Prompt user for input
    printf("Enter a string: ");
    fgets(inputString, MAX_STRING_SIZE, stdin);  // Get input from user

    // Remove newline character at the end of string
    inputString[strcspn(inputString, "\n")] = 0;

    // Loop through each character in input string
    for (int i = 0; i < strlen(inputString); i++) {

        // Check if current character is a space or punctuation
        if (isspace(inputString[i]) || ispunct(inputString[i])) {
            // Increment word count if previous character was not a space or punctuation
            if (!isspace(inputString[i-1]) && !ispunct(inputString[i-1])) {
                wordCount++;
            }
        }

    }

    // Increment word count by 1 if the last character in the string is not a space or punctuation
    if (!isspace(inputString[strlen(inputString)-1]) && !ispunct(inputString[strlen(inputString)-1])) {
        wordCount++;
    }

    // Output word count to user
    printf("Word count: %d\n", wordCount);

    return 0;
}