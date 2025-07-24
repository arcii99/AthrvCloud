//FormAI DATASET v1.0 Category: Spell checking ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_SIZE 50
#define MAX_DICTIONARY_SIZE 1000

// Function to check if a word is in the dictionary
bool isWordInDictionary(char word[], char dictionary[][MAX_WORD_SIZE], int dictSize) {
    for (int i = 0; i < dictSize; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_SIZE]; // Store the dictionary of words
    int dictSize = 0; // Keep track of the number of words in the dictionary
    char word[MAX_WORD_SIZE]; // Store the word to be spell checked

    // Load the dictionary of words from a file
    FILE *f = fopen("dictionary.txt", "r");
    if (f) {
        while (fgets(dictionary[dictSize], MAX_WORD_SIZE, f)) {
            dictionary[dictSize][strlen(dictionary[dictSize]) - 1] = '\0'; // Remove the newline character from the end
            dictSize++;
        }
        fclose(f);
    }

    // Get the word to be spell checked from the user
    printf("Enter a word to check its spelling:\n");
    scanf("%s", word);

    // Check if the word is in the dictionary
    if (isWordInDictionary(word, dictionary, dictSize)) {
        printf("The word \"%s\" is spelled correctly!\n", word);
    } else {
        printf("The word \"%s\" is spelled incorrectly!\n", word);
    }

    return 0;
}