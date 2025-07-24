//FormAI DATASET v1.0 Category: Spell checking ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50    // Max length of a word in the dictionary file
#define MAX_LINE_LENGTH 500   // Max length of a line in the input file
#define MAX_MISTAKES 3        // Max number of mistakes allowed per line

// Function to check if a word is present in the dictionary
int lookup(char *word, char dictionary[][MAX_WORD_LENGTH], int dictionary_size) {
    int i;
    for (i = 0; i < dictionary_size; ++i) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    // Load the dictionary file
    char dictionary[5000][MAX_WORD_LENGTH];
    int dictionary_size = 0, i;
    FILE *dict_file = fopen("dictionary.txt", "r");
    if (!dict_file) {
        printf("Error reading dictionary file\n");
        return -1;
    }
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, dict_file)) {
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';   // Remove the newline character
        }
        // Convert all lowercase to uppercase
        for (i = 0; line[i]; ++i) {
            line[i] = toupper(line[i]);
        }
        strcpy(dictionary[dictionary_size++], line);
    }
    fclose(dict_file);
    printf("Dictionary loaded successfully\n");

    // Open the input file for spell checking
    FILE *input_file = fopen("input.txt", "r");
    if (!input_file) {
        printf("Error reading input file\n");
        return -1;
    }

    // Start spell checking each line of the input file
    while (fgets(line, MAX_LINE_LENGTH, input_file)) {
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';   // Remove the newline character
        }
        char *word = strtok(line, " \t");   // Get the first word of the line
        int mistake_count = 0;              // Counter for the number of mistakes in the line
        while (word) {
            // Convert all lowercase to uppercase
            for (i = 0; word[i]; ++i) {
                word[i] = toupper(word[i]);
            }
            if (!lookup(word, dictionary, dictionary_size)) {
                printf("Incorrect spelling: %s\n", word);
                mistake_count++;
                if (mistake_count >= MAX_MISTAKES) {
                    printf("Too many mistakes in line\n");
                    break;
                }
            }
            word = strtok(NULL, " \t");   // Get the next word of the line
        }
    }

    fclose(input_file);
    return 0;
}