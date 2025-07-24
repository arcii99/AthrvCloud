//FormAI DATASET v1.0 Category: Spell checking ; Style: detailed
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICTIONARY_WORDS 10000

int main(int argc, char *argv[]) {

    // Load the dictionary file into a buffer
    char dictionary[MAX_DICTIONARY_WORDS][MAX_WORD_LENGTH+1];
    int numWords = 0;
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Dictionary file not found!\n");
        return -1;
    }
    while (fgets(dictionary[numWords], MAX_WORD_LENGTH+1, fp) != NULL) {
        // Remove trailing newline characters
        int len = strlen(dictionary[numWords]);
        if (len > 0 && dictionary[numWords][len-1] == '\n') {
            dictionary[numWords][len-1] = '\0';
        }
        numWords++;
    }
    fclose(fp);

    // Check each word in the input file against the dictionary
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Input file not found!\n");
        return -1;
    }
    char word[MAX_WORD_LENGTH+1];
    int line = 1;
    while (fscanf(fp, "%s", word) != EOF) {
        // Convert the word to lowercase for comparison
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }
        // Check if the word is in the dictionary
        int found = 0;
        for (int i = 0; i < numWords; i++) {
            if (strcmp(word, dictionary[i]) == 0) {
                found = 1;
                break;
            }
        }
        // Print an error message if the word is misspelled
        if (!found) {
            printf("Misspelled word '%s' on line %d\n", word, line);
        }
        // Increment the line counter if a newline character is encountered
        for (int i = 0; word[i]; i++) {
            if (word[i] == '\n') {
                line++;
            }
        }
    }
    fclose(fp);

    return 0;
}