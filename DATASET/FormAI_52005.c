//FormAI DATASET v1.0 Category: Word Count Tool ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the number of words in a given string
int countWords(char *str) {
    int count = 0;
    int inWord = 0;

    // Loop through each character in the string
    for (int i = 0; str[i] != '\0'; i++) {
        // Increment the counter if the current character is not a space
        if (str[i] != ' ') {
            inWord = 1;
        }
        // If we're currently in a word and we've reached the end of the word, increment the counter
        if (inWord && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')) {
            count++;
            inWord = 0;
        }
    }

    // Return the total word count
    return count;
}

int main() {
    char input[1024];

    // Display intro message
    printf("Welcome to the Post-Apocalyptic Word Count Tool\n\n");

    // Loop until the user enters an empty string
    do {
        printf("\nEnter a string to count the number of words (or press Enter to quit): ");
        fgets(input, 1024, stdin);

        // Remove newline character from input if it exists
        int len = strlen(input);
        if (len > 0 && input[len-1] == '\n') {
            input[len-1] = '\0';
        }

        // If the input is not empty, count the words and display the result
        if (strlen(input) > 0) {
            int wordCount = countWords(input);
            printf("\nThere are %d words in \"%s\".\n", wordCount, input);
        }
    } while (strlen(input) > 0);

    // Display exit message
    printf("\nThank you for using the Post-Apocalyptic Word Count Tool. Stay safe out there.\n");

    return 0;
}