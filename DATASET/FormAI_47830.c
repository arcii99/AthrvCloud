//FormAI DATASET v1.0 Category: Spell checking ; Style: Ada Lovelace
// Program to perform spell checking in Ada Lovelace style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a word is spelled correctly
int spellCheck(char *word) {
    // Dictionary of correctly spelled words
    char dictionary[10][20] = {"algorithm", "analytics", "analytical", "computing", "compiler", "cybersecurity", "debugging", "programmer", "software", "syntax"};

    // Convert word to lowercase
    for (int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }

    // Check if word is in dictionary
    for (int i = 0; i < 10; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            // Word is spelled correctly
            return 1;
        }
    }

    // Word is misspelled
    return 0;
}

// Main function
int main() {
    char text[1000];
    char word[20];
    int i = 0, j = 0;

    // Prompt user to input text
    printf("Input text: ");
    fgets(text, 1000, stdin);

    // Check each word in text for spelling errors
    while (text[i] != '\0') {
        // Check if character is alphabetical
        if (isalpha(text[i])) {
            word[j++] = text[i];
        }
        // End of word reached
        else {
            word[j] = '\0';
            // Check if word is spelled correctly
            if (!spellCheck(word)) {
                printf(" \"%s\" is misspelled.\n", word);
            }
            j = 0;   // Reset word index
        }
        i++;   // Move to next character in text
    }

    return 0;
}