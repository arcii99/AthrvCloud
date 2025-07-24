//FormAI DATASET v1.0 Category: Spell checking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void check_spelling(char *word, char *dictionary[], int size);

int main() {
    int dictionary_size = 5;
    char *dictionary[] = {"apple", "banana", "carrot", "orange", "pear"};

    printf("Enter a sentence to check for spelling errors:\n");
    char input[100];
    fgets(input, 100, stdin);

    // Separate each word in the sentence
    char *word = strtok(input, " ");
    while (word != NULL) {
        check_spelling(word, dictionary, dictionary_size);
        word = strtok(NULL, " ");
    }

    return 0;
}

void check_spelling(char *word, char *dictionary[], int size) {
    char lowercase_word[20];
    int i;
    for (i = 0; i < strlen(word); i++) {
        lowercase_word[i] = tolower(word[i]);
    }
    lowercase_word[i] = '\0';

    for (i = 0; i < size; i++) {
        if (strcmp(lowercase_word, dictionary[i]) == 0) {
            return; // Word is spelled correctly
        }
    }

    // Word is spelled incorrectly
    printf("Did you mean: ");
    for (i = 0; i < size; i++) {
        // Check for words that are close in spelling
        if (abs((int) strlen(lowercase_word) - (int) strlen(dictionary[i])) <= 1) {
            int mismatches = 0;
            int j;
            for (j = 0; j < strlen(lowercase_word); j++) {
                if (lowercase_word[j] != dictionary[i][j]) {
                    mismatches++;
                }
            }
            if (mismatches <= 1) {
                printf("%s ", dictionary[i]);
            }
        }
    }
    printf("\n");
}