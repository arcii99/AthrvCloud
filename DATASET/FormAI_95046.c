//FormAI DATASET v1.0 Category: Spell checking ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DICTIONARY_SIZE 1000
#define WORD_SIZE 50

// Function to load words from a file into an array
void loadWordsFromFile(FILE *file, char dictionary[][WORD_SIZE]) {
    int i = 0;
    char word[WORD_SIZE];

    while (fgets(word, WORD_SIZE, file) != NULL && i < DICTIONARY_SIZE) {
        // Remove newline character at the end
        word[strcspn(word, "\n")] = '\0';

        // Copy the word into the array
        strcpy(dictionary[i], word);
        i++;
    }
}

// Function to check if a word is in the dictionary
int isWordInDictionary(char dictionary[][WORD_SIZE], char *word) {
    for (int i = 0; i < DICTIONARY_SIZE; i++) {
        if (strcmp(dictionary[i], word) == 0) {
            return 1; // word found
        }
    }
    return 0; // word not found
}

// Function to check if a word contains only letters
int isWordOnlyLetters(char *word) {
    for (int i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i])) {
            return 0; // word contains non-letter character
        }
    }
    return 1; // word contains only letters
}

// Function to check if a word is spelled correctly
int checkWord(char dictionary[][WORD_SIZE], char *word) {
    if (!isWordOnlyLetters(word)) {
        return 0; // word contains non-letter character
    }

    if (!isWordInDictionary(dictionary, word)) {
        return 0; // word not found in dictionary
    }

    return 1; // word spelled correctly
}

int main() {
    // Load words from file into dictionary array
    char dictionary[DICTIONARY_SIZE][WORD_SIZE];
    FILE *file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        printf("Error opening dictionary file\n");
        exit(1);
    }
    loadWordsFromFile(file, dictionary);
    fclose(file);

    // Check words from standard input
    printf("Enter some words to check their spelling (press Ctrl+D when finished):\n");
    char currentWord[WORD_SIZE];
    int isWordSpelledCorrectly;
    while (fgets(currentWord, WORD_SIZE, stdin) != NULL) {
        currentWord[strcspn(currentWord, "\n")] = '\0'; // Remove newline character

        // Check if word is spelled correctly
        isWordSpelledCorrectly = checkWord(dictionary, currentWord);

        // Print result
        if (isWordSpelledCorrectly) {
            printf("%s is spelled correctly\n", currentWord);
        } else {
            printf("%s is misspelled\n", currentWord);
        }
    }

    return 0;
}