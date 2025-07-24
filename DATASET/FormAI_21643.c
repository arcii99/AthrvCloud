//FormAI DATASET v1.0 Category: Word Count Tool ; Style: standalone
#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main()
{
    char input[MAX_LENGTH];
    int word_count = 0;
    int char_count = 0;
    int i = 0;

    printf("Welcome to the C Word Count Tool\n");
    printf("Enter your text: ");

    // Read the input until the end of the line or until the maximum length is reached
    while (fgets(input, MAX_LENGTH, stdin)) {
        // Loop through each character in the input
        for (i = 0; input[i] != '\0'; i++) {
            // If the character is a space, a tab or a newline, we assume it's the end of a word
            if (isspace(input[i])) {
                // If we have found a word, increment the word count
                if (char_count > 0) {
                    word_count++;
                    char_count = 0;
                }
            } else {
                // If the character is not a space, a tab or a newline, we assume it's part of a word
                char_count++;
            }
        }
        // If we have found the end of a line, we assume it's the end of a word
        if (char_count > 0) {
            word_count++;
            char_count = 0;
        }
        // Print the word count
        printf("Word count: %d\n", word_count);

        // Clear the input buffer
        fflush(stdin);

        // Reset the word count
        word_count = 0;

        // Ask for more input
        printf("Enter your text: ");
    }

    printf("Goodbye!\n");

    return 0;
}