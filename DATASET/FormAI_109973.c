//FormAI DATASET v1.0 Category: Text processing ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

int main() {
    char line[MAX_LINE_LENGTH];
    int line_count = 0, word_count = 0, char_count = 0;

    printf("Enter text: \n");

    while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
        // Remove trailing newline character
        line[strcspn(line, "\n")] = 0;

        // Skip empty lines
        if (strlen(line) == 0) continue;

        // Count number of lines
        line_count++;

        // Count number of characters
        char_count += strlen(line);

        // Count number of words
        char *token = strtok(line, " ");
        while (token != NULL) {
            word_count++;
            token = strtok(NULL, " ");
        }
    }

    printf("\nNumber of lines: %d\n", line_count);
    printf("Number of words: %d\n", word_count);
    printf("Number of characters: %d\n", char_count);

    return 0;
}