//FormAI DATASET v1.0 Category: Spell checking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICTIONARY_WORDS 1000

// Function to remove punctuation from a string
char* remove_punctuation(char* string) {
    int i, j = 0;
    char* result = (char*) malloc(strlen(string) + 1);

    for (i = 0; string[i] != '\0'; i++) {
        if (isalpha(string[i])) {
            result[j] = tolower(string[i]);
            j++;
        }
    }

    result[j] = '\0';
    return result;
}

// Function to check if a word is in the dictionary
int check_word(char* word, char** dictionary, int num_words) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char* dictionary[MAX_DICTIONARY_WORDS]; // Array to hold dictionary words
    int num_words = 0; // Number of words in the dictionary
    char line[MAX_WORD_LENGTH]; // Buffer to hold each line of the input file

    // Open the dictionary file and read in the words
    FILE* dictionary_file = fopen("dictionary.txt", "r");

    if (!dictionary_file) {
        printf("Error: Unable to open dictionary file.\n");
        return 1;
    }

    while (fgets(line, MAX_WORD_LENGTH, dictionary_file)) {
        // Remove newline character from end of line
        line[strcspn(line, "\n")] = '\0';

        // Add the word to the dictionary
        dictionary[num_words] = strdup(line);
        num_words++;
    }

    fclose(dictionary_file);

    // Open the input file and check the words
    FILE* input_file = fopen("input.txt", "r");

    if (!input_file) {
        printf("Error: Unable to open input file.\n");
        return 1;
    }

    printf("Misspelled words:\n");

    while (fgets(line, MAX_WORD_LENGTH, input_file)) {
        // Remove newline character from end of line
        line[strcspn(line, "\n")] = '\0';

        // Tokenize the line into words
        char* token = strtok(line, " ");

        while (token != NULL) {
            char* word = remove_punctuation(token);

            if (strlen(word) > 0 && !check_word(word, dictionary, num_words)) {
                printf("%s\n", token);
            }

            free(word);
            token = strtok(NULL, " ");
        }
    }

    fclose(input_file);

    return 0;
}