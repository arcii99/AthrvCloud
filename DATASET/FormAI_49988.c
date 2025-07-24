//FormAI DATASET v1.0 Category: Spell checking ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

// Cyberpunk style error handling function
void error(const char* msg) {
    printf("Error: %s\n", msg);
    exit(1);
}

int main(void) {
    char dict[MAX_WORDS][MAX_WORD_LENGTH];
    int word_count = 0;
    char user_input[MAX_WORD_LENGTH];
    int misspelled_count = 0;
    int i, j;

    // Read in dictionary file
    FILE *dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        error("Unable to open dictionary file");
    }
    while (fgets(dict[word_count], MAX_WORD_LENGTH, dict_file)) {
        word_count++;
    }
    fclose(dict_file);

    // Remove newline characters from dictionary words
    for (i = 0; i < word_count; i++) {
        dict[i][strlen(dict[i]) - 1] = '\0';
    }

    // Get user input and check for misspellings
    printf("Enter a sentence: ");
    fgets(user_input, MAX_WORD_LENGTH, stdin);
    for (i = 0; i < strlen(user_input); i++) {
        // Convert to lower case and remove punctuation
        user_input[i] = tolower(user_input[i]);
        if (!isalpha(user_input[i]) && user_input[i] != ' ') {
            user_input[i] = ' ';
        }
    }
    char *word = strtok(user_input, " ");
    while (word != NULL) {
        // Strip leading/trailing whitespace from word
        while (isspace(*word)) {
            word++;
        }
        if (*word == '\0') {
            break;
        }
        char *end = word + strlen(word) - 1;
        while (end > word && isspace(*end)) {
            end--;
        }
        *(end+1) = '\0';

        // Check if word is in dictionary
        for (j = 0; j < word_count; j++) {
            if (strcmp(word, dict[j]) == 0) {
                break;
            }
        }
        if (j == word_count) {
            printf("Misspelled word: %s\n", word);
            misspelled_count++;
        }
        word = strtok(NULL, " ");
    }

    // Return number of misspelled words
    printf("Number of misspelled words: %d\n", misspelled_count);
    return 0;
}