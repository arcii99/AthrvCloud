//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: safe
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main(void) {
    char input[MAX_LENGTH];
    int charCount = 0, wordCount = 0, lineCount = 0, freqCount = 0;
    int ch, i, j;
    int freq[MAX_LENGTH];

    // Set frequency array to 0
    for (i = 0; i < MAX_LENGTH; i++) {
        freq[i] = 0;
    }

    // Read lines of input
    while (fgets(input, MAX_LENGTH, stdin) != NULL) {
        lineCount++;

        // Loop through each character of the input
        for (i = 0; input[i] != '\0'; i++) {
            // Increment character count
            charCount++;

            // Check if the character is a letter or digit
            if (isalnum(input[i])) {
                // If the character is the first of a new word, increment word count
                if (!isalnum(input[i-1])) {
                    wordCount++;
                }

                // Convert uppercase letters to lowercase
                if (isupper(input[i])) {
                    input[i] = tolower(input[i]);
                }

                // Calculate frequency of letter
                freq[input[i] - 'a']++;
            }
        }
    }

    // Print results
    printf("Number of characters: %d\n", charCount);
    printf("Number of words: %d\n", wordCount);
    printf("Number of lines: %d\n", lineCount);

    printf("\nLetter frequencies:\n");
    for (i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            printf("%c: %d\n", i + 'a', freq[i]);

            // Increment frequency count
            freqCount++;
        }
    }

    // Print total number of non-zero frequencies
    printf("\nNumber of non-zero letter frequencies: %d\n", freqCount);

    return 0;
}