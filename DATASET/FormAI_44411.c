//FormAI DATASET v1.0 Category: Spell checking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICT_WORDS 10000
#define MAX_TEXT_WORDS 1000

// Struct to hold each word in the dictionary
typedef struct {
    char word[MAX_WORD_LENGTH];
} word;

// Function to check if a given word is in the dictionary
bool check_spelling(word* dict, int dict_size, char* word_to_check) {
    // Convert the word to lowercase
    char lowercase_word[MAX_WORD_LENGTH];
    strcpy(lowercase_word, word_to_check);
    for (int i = 0; lowercase_word[i]; i++) {
        lowercase_word[i] = tolower(lowercase_word[i]);
    }
    // Use binary search to find the word in the dictionary
    int left = 0, right = dict_size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(lowercase_word, dict[mid].word);
        if (cmp == 0) {
            return true;
        } else if (cmp < 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return false;
}

int main() {
    // Load the dictionary into an array
    word* dict = malloc(MAX_DICT_WORDS * sizeof(word));
    if (dict == NULL) {
        printf("Error: malloc failed to allocate memory\n");
        return 1;
    }
    FILE* dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        printf("Error: could not open dictionary file\n");
        free(dict);
        return 1;
    }
    int dict_size = 0;
    char buffer[MAX_WORD_LENGTH];
    while (fgets(buffer, MAX_WORD_LENGTH, dict_file) != NULL && dict_size < MAX_DICT_WORDS) {
        // Remove newline character from the end of the buffer
        buffer[strcspn(buffer, "\n")] = 0;
        strcpy(dict[dict_size].word, buffer);
        dict_size++;
    }
    fclose(dict_file);
    printf("Dictionary loaded successfully with %d words.\n", dict_size);

    // Get text to check spelling on
    char** text = malloc(MAX_TEXT_WORDS * sizeof(char*));
    if (text == NULL) {
        printf("Error: malloc failed to allocate memory\n");
        free(dict);
        return 1;
    }
    printf("Enter text to check spelling on (maximum of %d words):\n", MAX_TEXT_WORDS);
    int text_size = 0;
    while (text_size < MAX_TEXT_WORDS) {
        // Allocate memory for the next word
        char* new_word = malloc(MAX_WORD_LENGTH * sizeof(char));
        if (new_word == NULL) {
            printf("Error: malloc failed to allocate memory\n");
            for (int i = 0; i < text_size; i++) {
                free(text[i]);
            }
            free(text);
            free(dict);
            return 1;
        }
        // Read the next word
        scanf("%s", new_word);
        // Check if the word is in the dictionary
        if (!check_spelling(dict, dict_size, new_word)) {
            printf("Misspelled word: %s\n", new_word);
        }
        // Add the word to the text array
        text[text_size] = new_word;
        text_size++;
    }

    // Free memory and exit
    for (int i = 0; i < text_size; i++) {
        free(text[i]);
    }
    free(text);
    free(dict);
    return 0;
}