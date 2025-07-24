//FormAI DATASET v1.0 Category: Word Count Tool ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the number of words in a string
int countWords(char* str) {
    int count = 0, i;

    // Loop through each character in the string
    for (i = 0; str[i] != '\0'; i++) {
        // If current character is a whitespace character, increment the word count
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            count++;
        }
    }

    // Increment count for the last word
    count++;

    return count;
}

int main() {
    char input[1000];

    // Prompt the user to enter a string
    printf("Enter a string: ");
    fgets(input, 1000, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;

    // Count the number of words in the input string
    int wordCount = countWords(input);

    // Print the number of words in the input string
    printf("Number of words in the string: %d\n", wordCount);

    return 0;
}