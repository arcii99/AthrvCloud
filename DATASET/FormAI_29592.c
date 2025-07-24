//FormAI DATASET v1.0 Category: Spell checking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define DICTIONARY_SIZE 1000

// Function to read dictionary of words
int readDictionary(char *filename, char dictionary[][MAX_WORD_LEN]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return -1;
    }
    int i = 0;
    while (fgets(dictionary[i], MAX_WORD_LEN, file)) {
        dictionary[i][strcspn(dictionary[i], "\n")] = '\0'; // Remove newline character
        i++;
    }
    fclose(file);
    return i;
}

// Function to check if a word is spelled correctly
int checkSpelling(char *word, char dictionary[][MAX_WORD_LEN], int dictSize) {
    for (int i = 0; i < dictSize; i++) {
        if (strcmp(dictionary[i], word) == 0) {
            return 1; // Word is spelled correctly
        }
    }
    return 0; // Word is spelled incorrectly
}

int main() {
    char dictionary[DICTIONARY_SIZE][MAX_WORD_LEN];
    char word[MAX_WORD_LEN];
    int dictSize = readDictionary("dictionary.txt", dictionary);
    if (dictSize == -1) {
        return -1;
    }
    printf("Enter a sentence (press CTRL+D to exit):\n");
    while (scanf("%s", word) != EOF) {
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]); // Convert to lowercase for case-insensitive comparison
            if (!isalpha(word[i])) {
                // Word contains non-letter characters, skip checking
                continue;
            }
            if (!checkSpelling(word, dictionary, dictSize)) {
                // Word is spelled incorrectly, prompt user for correction
                char correction[MAX_WORD_LEN];
                printf("'%s' is not spelled correctly. What should it be? ", word);
                scanf("%s", correction);
                strcpy(word, correction); // Replace misspelled word with correction
            }
        }
        printf("%s ", word);
    }
    printf("\n");
    return 0;
}