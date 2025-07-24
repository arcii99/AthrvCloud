//FormAI DATASET v1.0 Category: Spell checking ; Style: genious
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50 // Maximum length of a word
#define DICTIONARY_SIZE 100 // Maximum number of words in the dictionary

// Global variables
char dictionary[DICTIONARY_SIZE][MAX_WORD_LEN];
int dict_words = 0;

// Function to add a new word to the dictionary
void add_word_to_dict(char word[MAX_WORD_LEN]) {
    strcpy(dictionary[dict_words], word);
    dict_words++;
}

// Function to check if a word is in the dictionary
int is_word_in_dict(char word[MAX_WORD_LEN]) {
    for (int i = 0; i < dict_words; i++) {
        if (strcmp(dictionary[i], word) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to remove the trailing newline character from a string
void remove_newline(char string[MAX_WORD_LEN]) {
    char *newline = strchr(string, '\n');
    if (newline != NULL) {
        *newline = '\0';
    }
}

// Function to check the spelling of a word
void check_spelling(char word[MAX_WORD_LEN]) {
    // Remove any trailing newline character
    remove_newline(word);
    
    // Convert the word to lowercase
    for (int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }
    
    if (is_word_in_dict(word)) {
        // The word is in the dictionary
        printf("%s is spelled correctly!\n", word);
    } else {
        // The word is not in the dictionary
        printf("%s is spelled incorrectly.\nDid you mean:\n", word);
        
        for (int i = 0; i < dict_words; i++) {
            if (strlen(dictionary[i]) == strlen(word)) {
                // Words of the same length may be potential matches
                int distance = 0;
                for (int j = 0; j < strlen(word); j++) {
                    if (word[j] != dictionary[i][j]) {
                        distance++;
                    }
                }
                if (distance <= 1) {
                    // Display the potential match
                    printf("- %s\n", dictionary[i]);
                }
            }
        }
    }
}

// Main function
int main() {
    // Add some words to the dictionary
    add_word_to_dict("hello");
    add_word_to_dict("world");
    add_word_to_dict("programming");
    add_word_to_dict("language");
    
    // Get input from the user
    char word[MAX_WORD_LEN];
    printf("Enter a word to check the spelling: ");
    fgets(word, MAX_WORD_LEN, stdin);
    
    // Check the spelling of the word
    check_spelling(word);
    
    return 0;
}