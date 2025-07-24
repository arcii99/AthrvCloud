//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: all-encompassing
/* This program implements a C Cat Language Translator that converts English language statements to Cat language statements. It works by replacing certain English words with their Cat equivalent, resulting in translated statements that can be understood by cats. */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define BUF_SIZE 100

// Helper function to check if a given word is a valid English word
bool is_valid_word(char *word) {
    // In this implementation, any non-empty string is considered a valid word
    return strlen(word) > 0;
}

// Helper function to convert an English word to its Cat equivalent
// Returns the original word if it does not have a Cat equivalent
char *english_to_cat(char *word) {
    // List of English words and their Cat equivalents
    char *english_words[] = {"food", "water", "sleep", "play"};
    char *cat_words[] = {"meow", "purr", "nap", "pounce"};

    // Check if the given word has a Cat equivalent
    for (int i = 0; i < sizeof(english_words) / sizeof(english_words[0]); i++) {
        if (strcmp(english_words[i], word) == 0) {
            return cat_words[i];
        }
    }

    // If the word does not have a Cat equivalent, return the original word
    return word;
}

// Main program logic
int main() {
    char buffer[BUF_SIZE];  // Input buffer to read statements
    char *word;             // Pointer to current word in statement
    char *translated_word;  // Pointer to translated word

    // Read statements from standard input until EOF is reached
    while (fgets(buffer, BUF_SIZE, stdin) != NULL) {
        // Split statement into words using space as delimiter
        word = strtok(buffer, " ");

        while (word != NULL) {
            // Check if the word is a valid English word
            if (is_valid_word(word)) {
                // Convert the word to its Cat equivalent
                translated_word = english_to_cat(word);
                // Print the translated word to standard output
                printf("%s ", translated_word);
            } else {
                // Print the original non-word character to standard output
                printf("%s", word);
            }

            // Move to the next word in the statement
            word = strtok(NULL, " ");
        }

        // Print a newline character after each statement
        printf("\n");
    }

    return 0;
}