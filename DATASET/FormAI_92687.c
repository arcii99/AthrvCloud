//FormAI DATASET v1.0 Category: Spell checking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// A function to check whether a given word is spelled correctly or not
int check_spelling(char *word, char **dictionary, int dict_size) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // word is correctly spelled
        }
    }
    return 0; // word is spelled incorrectly
}

int main() {
    printf("Welcome to our unique spell checking program!\n\n");
    printf("Please enter the word(s) you want to check (max 100 chars): ");

    char input[100];
    fgets(input, sizeof(input), stdin);

    // Convert all characters to lowercase
    for (int i = 0; input[i]; i++) {
        input[i] = tolower(input[i]);
    }

    // Tokenize the input string
    char *token = strtok(input, " ,.-\n");

    int num_errors = 0;
    int num_words = 0;

    // Load the dictionary file into memory
    FILE *file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        printf("Error: could not open dictionary file!\n");
        return 1;
    }

    char *dictionary[10000];
    int dict_size = 0;

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        // Remove newline character at the end of each line
        line[strcspn(line, "\n")] = 0;

        dictionary[dict_size] = strdup(line); // make a copy of the line
        dict_size++;
    }

    // Close the dictionary file
    fclose(file);

    // Loop through all tokens in the input and check their spelling
    while (token != NULL) {
        if (!check_spelling(token, dictionary, dict_size)) {
            printf("Error: '%s' is spelled incorrectly!\n", token);
            num_errors++;
        }
        num_words++;

        token = strtok(NULL, " ,.-\n"); // move to the next token
    }

    // Print results summary
    if (num_words == 0) {
        printf("\nError: no words found in input!\n");
    } else if (num_errors == 0) {
        printf("\nCongratulations: all words are spelled correctly!\n");
    } else {
        printf("\nSummary:\n");
        printf("Total words checked: %d\n", num_words);
        printf("Number of misspelled words: %d\n", num_errors);
        float error_rate = (float) num_errors / num_words * 100;
        printf("Error rate: %.2f%%\n", error_rate);
    }

    // Free memory used by the dictionary array
    for (int i = 0; i < dict_size; i++) {
        free(dictionary[i]);
    }

    return 0;
}