//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: satisfied
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 20   // Maximum word length
#define ALPHABET_SIZE 26     // Number of letters in the English alphabet

// Function to read a single word from the input stream
bool read_word(char *word, int max_word_length) {
    int c;
    bool in_word = false;
    int word_length = 0;

    // Read characters until a word is complete or we reach the end of the file
    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {   // If the character is a letter
            if (!in_word) {
                in_word = true;
            }
            if (word_length < max_word_length) {
                word[word_length++] = tolower(c);
            }
        } else {    // If the character is not a letter
            if (in_word) {
                break;
            }
        }
    }

    if (word_length == 0 && c == EOF) { // Return false if we've reached the end of the file
        return false;
    }

    // Terminate the word string with a null character
    word[word_length] = '\0';

    return true;
}

int main(void) {
    int word_count[ALPHABET_SIZE][MAX_WORD_LENGTH + 1] = {0};   // Initialize all counts to 0
    char word[MAX_WORD_LENGTH + 1];

    // Read words from input and count their frequency
    while (read_word(word, MAX_WORD_LENGTH)) {
        int letter_index = word[0] - 'a';
        int word_length = strlen(word);

        word_count[letter_index][word_length]++;
    }

    // Print the frequency of each word length for each letter
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        char current_letter = 'a' + i;
        printf("%c:\n", current_letter);

        for (int j = 1; j <= MAX_WORD_LENGTH; j++) {
            int count = word_count[i][j];
            if (count > 0) {
                printf("  %d word%s of length %d\n", count, (count == 1) ? "" : "s", j);
            }
        }
    }

    return EXIT_SUCCESS;
}