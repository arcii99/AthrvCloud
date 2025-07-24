//FormAI DATASET v1.0 Category: Spell checking ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define WORD_LENGTH 20
#define DICTIONARY_SIZE 10000

int dictionary_size = 0;
char dictionary[DICTIONARY_SIZE][WORD_LENGTH];

int add_word_to_dictionary(char *word) {
    // Function to add a new word to the dictionary
    if (dictionary_size >= DICTIONARY_SIZE) {
        printf("Cannot add more words. Dictionary is full.\n");
        return 0;
    }

    strcpy(dictionary[dictionary_size], word);
    dictionary_size++;
    return 1;
}

int search_dictionary(char *word) {
    // Function to search for a word in the dictionary
    for (int i = 0; i < dictionary_size; i++) {
        if (strcmp(dictionary[i], word) == 0) {
            return 1;
        }
    }
    return 0;
}

void check_spelling(char *filename) {
    // Function to check the spelling of words in a given file
    FILE *fp;
    char word[WORD_LENGTH];

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while (fscanf(fp, "%s", word) != EOF) {
        for (int i = 0; i < strlen(word); i++) {
            if (ispunct(word[i])) {
                // Remove any punctuation characters from the word
                memmove(&word[i], &word[i + 1], strlen(word) - i);
            }
            word[i] = tolower(word[i]);
        }

        if (!search_dictionary(word)) {
            // Word not found in dictionary
            printf("Misspelled word: %s\n", word);
            printf("Add '%s' to dictionary? (y/n)\n", word);

            char response;
            scanf("%c", &response);

            if (tolower(response) == 'y') {
                add_word_to_dictionary(word);
                printf("'%s' added to dictionary.\n", word);
            }
        }
    }

    fclose(fp);
}

int main() {
    // Add some initial words to the dictionary
    add_word_to_dictionary("hello");
    add_word_to_dictionary("world");
    add_word_to_dictionary("example");
    add_word_to_dictionary("program");

    // Check the spelling of a sample file
    check_spelling("sample.txt");

    // Print the contents of the dictionary
    printf("\nDictionary:\n");
    for (int i = 0; i < dictionary_size; i++) {
        printf("%s\n", dictionary[i]);
    }

    return 0;
}