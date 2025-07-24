//FormAI DATASET v1.0 Category: Spell checking ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to determine if a word is spelled correctly
int spellCheck(char* word) {
    // Lookup table for valid words
    char* validWords[] = {"computer", "programming", "language", "algorithm", "data", "structure"};

    // Number of valid words
    int numValidWords = 6;

    // Convert word to lowercase for case-insensitive comparison
    int i;
    for (i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }

    // Compare word to list of valid words
    for (i = 0; i < numValidWords; i++) {
        if (strcmp(word, validWords[i]) == 0) {
            // Word is valid
            return 1;
        }
    }

    // Word is not valid
    return 0;
}

int main() {
    // Declare variables
    char input[1000];
    char* word;
    char delimiters[] = " .,:;?!-()\t\n";

    // Prompt user for input
    printf("Enter text to spell check:\n");
    fgets(input, sizeof(input), stdin);

    // Tokenize input into individual words
    word = strtok(input, delimiters);
    while (word != NULL) {
        // Check if word is spelled correctly
        if (!spellCheck(word)) {
            printf("Invalid word: %s\n", word);
        }
        
        // Get next word
        word = strtok(NULL, delimiters);
    }

    // Exit program
    return 0;
}