//FormAI DATASET v1.0 Category: Spell checking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to check if a word is spelled correctly
int spellcheck(char *dictionary[], char *word, int range) {
    // Convert the word to lowercase
    char lowercase[50];
    int i;
    for (i = 0; i < strlen(word); i++) {
        lowercase[i] = tolower(word[i]);
    }
    lowercase[i] = '\0';

    // Binary search for the word in the dictionary
    int left = 0, right = range - 1;
    while (left <= right) {
        int mid = (left + right) / 2;

        if (strcmp(dictionary[mid], lowercase) < 0) {
            left = mid + 1;
        } else if (strcmp(dictionary[mid], lowercase) > 0) {
            right = mid - 1;
        } else {
            return 1; // Word is spelled correctly
        }
    }

    return 0; // Word is spelled incorrectly
}

int main() {
    // Load the dictionary into memory
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open dictionary file.\n");
        exit(1);
    }
    char *dictionary[100000];
    int range = 0;
    char line[50];
    while (fgets(line, sizeof(line), fp)) {
        line[strlen(line) - 1] = '\0'; // Remove the newline character
        dictionary[range] = malloc(sizeof(line));
        strcpy(dictionary[range], line);
        range++;
    }
    fclose(fp);

    // Prompt the user for text input
    printf("Enter some text to spell check:\n");
    char text[10000];
    fgets(text, sizeof(text), stdin);

    // Parse the text into words and spell check each word
    char delimiters[] = " .,;:?!()[]{}-\"";
    char *word = strtok(text, delimiters);
    while (word != NULL) {
        if (!spellcheck(dictionary, word, range)) {
            printf("Error: \"%s\" is not spelled correctly.\n", word);
        }
        word = strtok(NULL, delimiters);
    }

    // Free memory allocated for the dictionary
    int i;
    for (i = 0; i < range; i++) {
        free(dictionary[i]);
    }

    return 0;
}