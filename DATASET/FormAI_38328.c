//FormAI DATASET v1.0 Category: Spell checking ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 25
#define MAX_LINE_LENGTH 100

int main() {
    // Open the dictionary file and read it into memory
    FILE* dictionary_file = fopen("dictionary.txt", "r");
    if (dictionary_file == NULL) {
        printf("Error: Could not open dictionary file\n");
        return -1;
    }
    char dictionary[5000][MAX_WORD_LENGTH+1];
    int num_words = 0;
    while (fgets(dictionary[num_words], MAX_WORD_LENGTH+1, dictionary_file)) {
        // Remove trailing newline character if present
        char* pos;
        if ((pos=strchr(dictionary[num_words], '\n')) != NULL) {
            *pos = '\0';
        }
        num_words++;
    }

    // Process input text line by line
    char text[MAX_LINE_LENGTH+1];
    while (fgets(text, MAX_LINE_LENGTH+1, stdin)) {
        // Get individual words from the line
        char* word;
        for (word = strtok(text, " \t\n"); word != NULL; word = strtok(NULL, " \t\n")) {
            // Convert word to lowercase
            int i;
            for (i = 0; i < strlen(word); i++) {
                word[i] = tolower(word[i]);
            }
            // Check if word is in dictionary
            for (i = 0; i < num_words; i++) {
                if (strcmp(word, dictionary[i]) == 0) {
                    break;
                }
            }
            if (i == num_words) { // Word not found in dictionary
                printf("'%s' is misspelled\n", word);
                // TODO: Implement suggestions for misspelled words
            }
        }
    }

    // Close dictionary file
    fclose(dictionary_file);
    return 0;
}