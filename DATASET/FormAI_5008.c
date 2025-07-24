//FormAI DATASET v1.0 Category: Text processing ; Style: configurable
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000 // Maximum allowed length of a line

int main() {
    char line[MAX_LINE_LENGTH]; // Buffer to hold each line of input
    int line_num = 1; // Current line number
    int num_words = 0; // Total number of words in the input
    int num_chars = 0; // Total number of characters in the input
    int num_lines = 0; // Total number of lines in the input
    int num_vowels = 0; // Total number of vowels in the input
    int num_consonants = 0; // Total number of consonants in the input

    // Print instructions to user
    printf("Enter some text. Press Ctrl-D (Unix) or Ctrl-Z (Windows) to finish:\n");

    // Read in each line of input
    while (fgets(line, MAX_LINE_LENGTH, stdin)) {

        // Strip newline character from the end of the line
        line[strcspn(line, "\n")] = '\0';

        // Count the number of words in the line
        char *word = strtok(line, " ");
        while (word != NULL) {
            num_words++;
            word = strtok(NULL, " ");
        }

        // Count the number of characters in the line (excluding whitespace)
        for (int i = 0; i < strlen(line); i++) {
            if (!isspace(line[i])) {
                num_chars++;
            }
        }

        // Count the number of vowels and consonants in the line
        for (int i = 0; i < strlen(line); i++) {
            char c = tolower(line[i]);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                num_vowels++;
            } else if (isalpha(c)) {
                num_consonants++;
            }
        }

        line_num++;
    }

    // Count the number of lines in the input
    num_lines = line_num - 1;

    // Print out statistics about the input
    printf("Number of lines: %d\n", num_lines);
    printf("Number of words: %d\n", num_words);
    printf("Number of characters: %d\n", num_chars);
    printf("Number of vowels: %d\n", num_vowels);
    printf("Number of consonants: %d\n", num_consonants);

    return 0;
}